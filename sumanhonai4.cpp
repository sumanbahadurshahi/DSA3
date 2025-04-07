#include <iostream>
using namespace std;

void towersOfHanoi(int n, string src, string helper, string des) {
    if (n == 1) {
        cout << "Transfer disk " << n << " from " << src << " to " << des << endl;
        return;
    }
    
    towersOfHanoi(n - 1, src, des, helper);
    cout << "Transfer disk " << n << " from " << src << " to " << des << endl;
    towersOfHanoi(n - 1, helper, src, des);
} 

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    
    towersOfHanoi(n, "A", "B", "C");

    return 0;
}

