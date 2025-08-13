#include<iostream>
using namespace std;
bool is_sorted(int num[], int n) {
    if(n==1){
        return true;
    }
    if(num[n-1]<num[n-2]) {
        return false;
    }
    return is_sorted(num, n-1);
}
int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i =0;i<n;i++) {
        cin>>arr[i];
    }
    if(is_sorted(arr, n)) {
        cout<<"The array is sorted."<<endl;
    }else {
        cout<<"The array is not sorted."<<endl;
    }
    return 0;
    }
