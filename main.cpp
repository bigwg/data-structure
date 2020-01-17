#include <iostream>

void pivot_quick_sort(int *a, int start, int end);

void heap_sort(int *a, int start, int end);

void merge_sort(int *a, int start, int end);

int main() {
    int a[10] = {9, 1, 4, 3, 8, 0, 6, 2, 3, 10};
//    int a[4] = {1, 9, 4, 10};
    int length = 10;
//    pivot_quick_sort(a, 0, length - 1);
//    heap_sort(a, 0, length - 1);
    merge_sort(a, 0, length - 1);
    for (int i = 0; i < length; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
