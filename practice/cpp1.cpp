#include<iostream>
using namespace std;
int main() {
    int n,sum=0;
    cout<<"Enter the number of elements: ";
    cin>>n;
    for(int i=1; i<=n; i++) {
       
        if(i%3==0){
            sum+=i;

        }
        
        
    }
    cout<<sum<<" ";
}