//
// Created by zhaozhiwei on 2020/1/17.
//

void merge(int *a, int *tmp, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (a[i] < a[j]) {
            tmp[k] = a[i];
            i++;
        } else {
            tmp[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        tmp[k] = a[i];
        i++;
        k++;
    }
    while (j <= end) {
        tmp[k] = a[j];
        j++;
        k++;
    }
    for (int l = 0; l < k; l++) {
        a[start + l] = tmp[l];
    }
}

void split(int *a, int *tmp, int start, int end) {
    if (end <= start) {
        return;
    }
    int mid = (end + start) / 2;
    split(a, tmp, start, mid);
    split(a, tmp, mid + 1, end);
    merge(a, tmp, start, mid, end);
}

void merge_sort(int *a, int start, int end) {
    int tmp[end - start + 1];
    split(a, tmp, start, end);
}
