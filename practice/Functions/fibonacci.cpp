#include<iostream>
using namespace std;

void fibonacci(int n) {
    int a=0, b=1;
    if(n<0) {
        cout<<"Fibonacci sequence is not defined for negative numbers. "<<endl;
        return;
    } 
    else{
        cout<<"Fibonacci sequence: ";
        if(n==0) {
            cout<<a<<" ";   }
        else if(n==1) {
            cout<<a<<" "<<b<<" ";}
        else {
            cout<<a<<" "<<b<<" ";
            for(int i=3; i<=n; i++) {
                int next= a+b;
                cout<<next<<" ";
                a=b;
                b=next;

            }
        }
        }
    }
    
int main() {
    int num;
    cout<<"Enter the number of terms in Fibonacci sequence: ";
    cin>>num;
    fibonacci(num);
    cout<<endl;
    return 0;
}