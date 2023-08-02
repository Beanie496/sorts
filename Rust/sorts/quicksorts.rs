macro_rules! swap {
    ($x: expr, $y: expr) => {
        ($x, $y) = ($y, $x)
    }
}

pub fn quicksort_slice(arr: &mut [i32])
{
    if arr.len() == 0 {
        return;
    }

    let pivot = arr.len() - 1;
    let mut p1 = 0;
    let mut p2 = 0;

    while p2 < pivot {
        if arr[p2] < arr[pivot] {
            swap!(arr[p1], arr[p2]);
            p1 += 1;
        }
        p2 += 1;
    }

    swap!(arr[p1], arr[pivot]);

    quicksort_slice(&mut arr[0..p1]);
    quicksort_slice(&mut arr[(p1 + 1)..=pivot]);
}

pub fn quicksort_ptr(arr: &mut [i32])
{
    if arr.len() <= 1 {
        return;
    }
    
    let start = arr.as_mut_ptr();
    let end = unsafe { start.add(arr.len() - 1) };

    unsafe { partition(start, end); }
}

unsafe fn partition(start: *mut i32, end: *mut i32)
{
    if start >= end {
        return;
    }

    let pivot = end;
    let mut p1 = start;
    let mut p2 = start;

    while p2 < pivot {
        if *p2 < *pivot {
            swap!(*p1, *p2);
            p1 = p1.add(1);
        }
        p2 = p2.add(1);
    }

    swap!(*p1, *pivot);

    partition(start, p1.wrapping_sub(1));
    partition(p1.wrapping_add(1), end);
}
