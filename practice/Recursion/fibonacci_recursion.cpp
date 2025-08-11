#include<iostream>
using namespace std;
void fibonacci(int a, int b, int n) {
    if(n==0){
        return;
    }
    cout<< a << " ";
    fibonacci(b, a+b, n-1);

}
int main() {
    int n;
    cout<<"Enter the number of terms in Fibonacci series: ";
    cin>>n;
    cout<<"Fibonacci series up to "<<n<<" terms is: ";
    fibonacci(0,1,n);
    cout<<endl;
    return 0;
}