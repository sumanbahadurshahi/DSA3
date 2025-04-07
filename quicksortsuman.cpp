#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int l, int r) {
    int pivot = arr[l]; 
    int x = l, y = r;

    while (x < y) {
        while (arr[x] <= pivot && x < r) 
            x++; 
        while (arr[y] > pivot && y > l) // Fixed condition here
            y--; 
        if (x < y) 
            swap(arr[x], arr[y]);
    }
    swap(arr[y], arr[l]); // Swap pivot to its correct position
    return y;
}

void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
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

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

