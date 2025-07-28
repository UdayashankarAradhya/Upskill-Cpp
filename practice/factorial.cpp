#include<iostream>
using namespace std;
int main(){
    int n;
    unsigned long long prod=1;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        prod*=i;

    }
    cout<<"The product of first "<<n<<" natural numbers is: "<<prod<<endl;
    return 0;
}