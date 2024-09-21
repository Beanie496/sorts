use sorts::{
    counting_sort,
    quicksorts::{quicksort_ptr, quicksort_slice},
};

mod sorts;

fn main() {
    const LEN: usize = 10_000_000;

    let mut arr = sorts::make_array(LEN);
    quicksort_slice(&mut arr);

    let mut arr = sorts::make_array(LEN);
    quicksort_ptr(&mut arr);

    let mut arr = sorts::make_array(LEN);
    counting_sort(&mut arr);
}
