#include<iostream>
using namespace std;
int power(int base, int exponent) {
    int result=1;
    for(int i=0; i<exponent; i++){
        result*=base;

    }
    return result;
}
int main(){
    int base;
    int exponent;
    cout<<"Enter the base: ";
    cin>>base;
    cout<<"Enter the exponent: ";
    cin>>exponent;
    if(exponent < 0) {
        cout<<"Exponent should be a non-negative integer."<<endl;
        return 1;
    }
    else {
        cout<<"Result of "<<base<<" raised to the power of "<<exponent<<" is "<<power(base, exponent)<<endl;
    }
}