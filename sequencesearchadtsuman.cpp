#include <iostream>
using namespace std;

// ADT for an Array
class ArrayADT {
private:
    int arr[5];  // Fixed-size array
    int size;

public:
    // Constructor to initialize the array
    ArrayADT(int a[], int s) {
        size = s;
        for (int i = 0; i < size; i++) {
            arr[i] = a[i];
        }
    }

    // Linear Search Function
    int linearSearch(int n) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == n) {
                return i + 1;  // Return position (1-based index)
            }
        }
        return -1;  // Not found
    }
};

int main() {
    int arr[5] = {1, 22, 34, 5, 7};  // Sample array
    ArrayADT arrayADT(arr, 5);  // Create ADT object

    int num;
    cout << "Please enter an element to search: ";
    cin >> num;

    int result = arrayADT.linearSearch(num);
    
    if (result != -1) {
        cout << "Element found at position: " << result << endl;
    } else {
        cout << "No Element Found" << endl;
    }

    return 0;
}

