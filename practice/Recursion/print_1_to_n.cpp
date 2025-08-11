#include<iostream>
using namespace std;

void printnumbers(int n) {
    if(n==0){
        return;
    }
    
    printnumbers(n-1);
    cout<< n << " ";
}
int main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Numbers from 1 to "<<n<<" are: ";
    printnumbers(n);
    cout<<endl;
    return 0;
}