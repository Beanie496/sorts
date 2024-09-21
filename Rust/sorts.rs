use std::{arch::x86_64, convert::TryInto, iter};

pub mod quicksorts;

pub fn counting_sort(array: &mut [u32]) {
    let mut secondary_array = vec![0; array.len()];
    let Some(max): Option<usize> = array.iter().max().and_then(|&m| m.try_into().ok()) else {
        return;
    };
    // '+ 1' because it's 0 to max, not 1
    let mut counting_list: Vec<usize> = vec![0; max + 1];

    // count occurances of each number
    for item in array.iter() {
        counting_list[*item as usize] += 1;
    }

    // make each entry the cumulative sum of all the previous entries
    for index in 1..=max {
        counting_list[index] += counting_list[index - 1];
    }

    for item in array.iter() {
        let index = &mut counting_list[*item as usize];
        // this now refers to the last index of this number instead of how many
        // of this number there are
        *index -= 1;
        // insert
        secondary_array[*index] = *item;
    }

    array.copy_from_slice(&secondary_array);
}

pub fn make_array<T: Copy + From<u16>>(len: usize) -> Vec<T> {
    iter::from_fn(|| {
        let mut rand = 0;
        unsafe { x86_64::_rdrand16_step(&mut rand) };
        Some(T::from(rand))
    })
    .take(len)
    .collect()
}
