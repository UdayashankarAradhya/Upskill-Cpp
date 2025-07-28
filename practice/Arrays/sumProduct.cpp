#include<iostream>
using namespace std;
int sum(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];

    }
    return sum;
}
int prod(int arr[], int n){
    int product=1;
    for(int i=0;i<n;i++){
        product*=arr[i];
    }
    return product;
}
int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Sum of the array elements: "<<sum(arr, n)<<endl;
    cout<<"Product of the array elements: "<<prod(arr, n)<<endl;
    return 0;

}