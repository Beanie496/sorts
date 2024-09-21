use core::ptr::swap;

pub fn quicksort_slice(arr: &mut [i32]) {
    if arr.is_empty() {
        return;
    }

    let Some(&last) = arr.last() else {
        return;
    };
    let mut smaller = 0;

    for larger in 0..arr.len() {
        if arr[larger] < last {
            arr.swap(smaller, larger);
            smaller += 1;
        }
    }

    arr.swap(smaller, arr.len() - 1);

    quicksort_slice(&mut arr[..smaller]);
    quicksort_slice(&mut arr[(smaller + 1)..]);
}

pub fn quicksort_ptr(arr: &mut [i32]) {
    if arr.len() <= 1 {
        return;
    }

    let start = arr.as_mut_ptr();
    let end = unsafe { start.add(arr.len() - 1) };

    unsafe {
        partition(start, end);
    }
}

unsafe fn partition(start: *mut i32, end: *mut i32) {
    if start >= end {
        return;
    }

    let pivot = end;
    let mut p1 = start;
    let mut p2 = start;

    while p2 < pivot {
        if *p2 < *pivot {
            swap(p1, p2);
            p1 = p1.add(1);
        }
        p2 = p2.add(1);
    }

    swap(p1, pivot);

    partition(start, p1.wrapping_sub(1));
    partition(p1.wrapping_add(1), end);
}
