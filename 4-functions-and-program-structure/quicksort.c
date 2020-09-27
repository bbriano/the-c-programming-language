#include <stdio.h>

void quicksort(int v[], int left, int right);
void swap(int v[], int i, int j);
void print_array(int v[], int n);

int main() {
    int nums[] = { 5, 5, 6, 5, 8, 4, 8, 7, 4, 5 };
    print_array(nums, 10);
    quicksort(nums, 0, 9);
    print_array(nums, 10);
}

// Sorts v using quicksort algorithm
void quicksort(int v[], int left, int right) {
    int i, last;
    if (left >= right) return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    quicksort(v, left, last-1);
    quicksort(v, last+1, right);
}

// Interchange v[i] and v[j]
void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Prints an integer array
void print_array(int v[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}
