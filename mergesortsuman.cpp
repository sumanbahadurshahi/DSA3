#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;  // Size of left subarray
    int n2 = r - m;      // Size of right subarray

    int L[n1], R[n2]; // Temporary arrays

    // Copy data to temporary arrays
    for (int x = 0; x < n1; x++)
        L[x] = arr[l + x];
    for (int y = 0; y < n2; y++)
        R[y] = arr[m + 1 + y];

    int x = 0, y = 0, k = l; // Merge pointers

    while (x < n1 && y < n2) {
        if (L[x] <= R[y]) {
            arr[k] = L[x];
            x++;
        } else {
            arr[k] = R[y];
            y++;
        }
        k++;
    }

    // Copy remaining elements
    while (x < n1) {
        arr[k] = L[x];
        x++;
        k++;
    }
    while (y < n2) {
        arr[k] = R[y];
        y++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2; // Find the middle

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

