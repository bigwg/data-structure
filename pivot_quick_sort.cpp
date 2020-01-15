//
// Created by zhaozhiwei on 2020/1/15.
//
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
