#include<iostream>
using namespace std;
void printNumbers(int n) {
    if(n==0){
        return;

    }
    cout<< n << " ";
    printNumbers(n-1);

}
int main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Numbers from "<<n<<" to 1 are: ";
    printNumbers(n);
    cout<<endl;
    return 0;
    
}