pub mod mmpsc {
    use std::collections::VecDeque;
    use std::fmt::Debug;
    use std::sync::{Arc, Mutex};

    // Q: 呼び出し側が SendSync を実装してないと怒られる。trait でまとめるとダメ？
    pub trait SendSync: Send + Sync {}

    pub struct Sender<T: Send + Sync> {
        queue: Arc<Mutex<VecDeque<T>>>,
    }

    impl<T: Send + Sync> Sender<T> {
        pub fn send(&mut self, item: T) {
            self.queue.lock().unwrap().push_back(item)
        }
    }

    pub struct Receiver<T: Send + Sync> {
        queue: Arc<Mutex<VecDeque<T>>>,
    }

    // debug 目的でいまだけ Debug をつけている
    impl<T: Send + Sync + Debug> Receiver<T> {
        pub fn receive(&self) -> Option<T> {
            let item = loop {
                if let Some(item) = self.queue.lock().unwrap().pop_front() {
                    break Some(item);
                }
            };
            println!("item: {:?}", item);
            item
        }
    }

    pub fn channel<T: Send + Sync>() -> (Sender<T>, Receiver<T>) {
        let queue: Arc<Mutex<VecDeque<T>>> = Arc::new(Mutex::new(Default::default()));
        (
            Sender {
                queue: Arc::clone(&queue),
            },
            Receiver {
                queue: Arc::clone(&queue),
            },
        )
    }
}
