mod sorts;

fn main() {
    const LEN: usize = 10_000_000;

    let mut arr = sorts::make_array(LEN);
    sorts::quicksorts::quicksort_slice(&mut arr);

    let mut arr = sorts::make_array(LEN);
    sorts::quicksorts::quicksort_ptr(&mut arr);
}
