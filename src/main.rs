// Q: class の FFI

#[link(name = "test", kind = "static")]
extern "C" {
    fn hello_world();
}

struct Semaphore {

}

impl Semaphore {
    fn aquire(){

    }
    fn relase(){

    }
}

fn main() {
    unsafe {
        hello_world();
    }
}
