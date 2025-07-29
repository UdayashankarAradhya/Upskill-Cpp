#include<iostream>
using namespace std;

void swapMinAndMax(int arr[], int n) {
    if(n<=0) return;
    int minIndex = 0, maxIndex= 0;
    for(int i=0; i<n; i++){
        if(arr[i]<arr[minIndex]){
            minIndex=i;

        }
        if(arr[i]>arr[maxIndex]){
            maxIndex=i;

        }
    }
    swap(arr[minIndex],arr[maxIndex]);

}
int main(){
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    if(n<=0){
        cout<<"Enter a valid size greater than 0."<<endl;
        return 0;
    }
    else {
        int arr[n];
        cout<<"Enter the elements of the array: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];

        }
        swapMinAndMax(arr,n);
        cout<<"after swapping the min and max elements: ";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";

        }
        cout<<endl;
        return 0;

    }

}