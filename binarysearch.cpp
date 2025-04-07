#include <iostream>
using namespace std;

int binarysearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Corrected mid calculation
        if (arr[mid] == x) {
            return mid;  // Element found, return index
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Element not found
}

int main() {
    int num;
    int arr[10];
    int output;

    cout << "Enter 10 integers (sorted): " << endl;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number to search: ";
    cin >> num;

    output = binarysearch(arr, 0, 9, num);

    if (output == -1) {
        cout << "Searching element is not found." << endl;
    } else {
        cout << "Searching element found at index " << output << "." << endl;
    }

    return 0;
}

