use std::{os::unix::thread, thread::spawn};

use async_runtime::mmpsc;

// Q: class の FFI

#[link(name = "my_semaphore", kind = "static")]
extern "C" {
    fn acquire();
    fn try_acquire() -> bool;
    fn release();
    fn guard_acquire();
    fn guard_release();
    fn guard_try_acquire();
}

fn main() {
    // guard: 同時に操作されているかのチェック
    // token: リソースのチェック
    // チェックを通すとバッファから返す、通らなかったらNone
    // レシーバのループで
    // consume: binary semaphore, producer: semaphore
    // mpsc の consume時にtry_acquireでチェック

    let mut stock: Vec<i32> = Vec::new();

    let (tx, rx) = mmpsc::mmpsc::channel::<String>();

    for n in 1..101 {
        // 新しいアイテムを生産
        let item = n * 100;
        unsafe {
            // アイテム在庫へ追加
            guard_acquire();
            stock.push(item);
            guard_release();
            // 在庫管理カウントを+1する
            release();
        }
    }

    for n in 1..101 {
        unsafe {
            // 在庫生産されるまで待機し、在庫管理カウントを-1する
            acquire();
            // アイテム在庫から取出
            guard_acquire();
            let item = stock.pop();
            guard_release();
        }
    }

}
