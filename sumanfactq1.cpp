#include<iostream>
using namespace std;
int fact(int n){
    if(n==0||n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    int value;
    cout<<"Enter the value:"<<endl;
    cin>>value;
    cout<<"The factorial of the "<<value<<"\tis:"<<fact(value)<<endl;
    return 0;
}
