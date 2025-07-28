#include<iostream>
using namespace std;
int main() {
    int n,sum;
    cout<<"Enter the number of elements: ";
    cin>>n;
    for(int i=1; i<n; i++) {
        sum=0;
        if(i%3==0){
            sum+=i;

        }
        cout<<sum<<" ";
        
    }
}