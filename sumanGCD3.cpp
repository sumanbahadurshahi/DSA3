//42%24=18;
//24%18=6;
//18%6=0;
#include<iostream>
using namespace std;
int GCD(int a,int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
int main(){
    int a,b;
    cout<<"Enter the two value you want to solve GCD(HCF):"<<endl;
    cin>>a>>b;
    cout<<"The GcD of "<<a<<b<<"\tis:"<<GCD(a,b)<<endl;
    return 0;
}
