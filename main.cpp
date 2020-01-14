#include <iostream>

/**
 * 快速排序（单轴）
 * @param a
 * @param start
 * @param end
 */
void pivot_quick_sort(int *a, int start, int end) {
    int i = start;
    int j = end;
    int tmp = a[start];
    if (i >= j) {
        return;
    }
    while (i < j) {
        while (i < j && a[j] > tmp) {
            j--;
        }
        a[i] = a[j];
        while (i < j && a[i] <= tmp) {
            i++;
        }
        a[j] = a[i];
    }

    a[i] = tmp;
    pivot_quick_sort(a, start, i - 1);
    pivot_quick_sort(a, i + 1, end);
}

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

int main() {
    int a[10] = {9, 1, 4, 3, 8, 0, 6, 2, 3, 10};
//    int a[4] = {1, 9, 4, 10};
    int length = 10;
//    pivot_quick_sort(a, 0, length - 1);
    heap_sort(a, 0, length - 1);
    for (int i = 0; i < length; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
