// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int fib(int n){
    if(n<=1){
        return n;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main() {
    int value;
    cout<<"Enter the value:"<<endl;
    cin>>value;
    cout<<"The fibonacci series of"<<value<<"\tare:"<<fib(value)<<endl;
    return 0;
}
