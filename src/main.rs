// Q: class の FFI

#[link(name = "my_semaphore", kind = "static")]
extern "C" {
    fn acquire();
    fn try_acquire() -> bool;
    fn release();
}

fn main() {
    unsafe {
        let is_ok = try_acquire();
    }

    // guard: 同時に操作されているかのチェック
    // token: リソースのチェック
    // チェックを通すとバッファから返す、通らなかったらNone
    // レシーバのループで
    // consume: binary semaphore, producer: semaphore
    // mpsc の consume時にtry_acquireでチェック

}

