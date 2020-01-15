//
// Created by zhaozhiwei on 2020/1/15.
//
/**
 * 交换交表位置
 * @param a
 * @param i
 * @param j
 */
void swap(int *a, int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void build_heap(int *a, int start, int end) {
    if (start >= end) {
        return;
    }
    int i = start;
    while (i < end) {
        int left = 2 * i + 1;
        int right = left + 1;
        if (left > end) {
            return;
        }
        int be_exchange = left;
        if (right <= end && a[left] < a[right]) {
            be_exchange = right;
        }
        if (a[i] < a[be_exchange]) {
            swap(a, i, be_exchange);
            i = be_exchange;
        } else {
            return;
        }

    }
}

/**
 * 堆排序（大顶堆）
 * @param a
 * @param start
 * @param end
 */
void heap_sort(int *a, int start, int end) {
    for (int i = (end - start + 1) / 2 - 1; i >= 0; i--) {
        build_heap(a, i, end);
    }
    for (int j = end; j > 0; j--) {
        swap(a, 0, j);
        build_heap(a, 0, j - 1);
    }
}
