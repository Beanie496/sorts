use std::{arch::x86_64, iter};

pub mod counting_sort;
pub mod quicksorts;

pub fn make_array<T: Copy + From<u16>>(len: usize) -> Vec<T> {
    iter::from_fn(|| {
        let mut rand = 0;
        unsafe { x86_64::_rdrand16_step(&mut rand) };
        Some(T::from(rand))
    })
    .take(len)
    .collect()
}
