use std::arch::x86_64;

pub mod quicksorts;

pub fn make_array<T: Copy>(len: usize) -> Vec<T>
{
    let mut arr: Vec<T> = Vec::with_capacity(len);
    init_array(&mut arr);
    arr
}

fn init_array<T: Copy>(arr: &mut Vec<T>)
{
    // TODO: figure out how to make this hardware-general
    for _i in 0..arr.capacity() {
        // TODO: surely there's a better way to do this?
        unsafe {
            union U<T: Copy> {
                x: u64,
                y: T,
            }
            let mut u = U { x: 0 };
            x86_64::_rdrand64_step(&mut u.x);
            arr.push(u.y);
        }
    }
}
