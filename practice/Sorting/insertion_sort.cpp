#include<iostream>
#include<vector>
using namespace std;
void insertion_sort(vector<int> &arr){
    int n=arr.size();
    int key;
    for(int i=1;i<n;i++){
        key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;

    }
}
void printarray(const vector<int> &arr){
    int n=arr.size();
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> arr;
    int n, element;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>element;
        arr.push_back(element);
    }
    insertion_sort(arr);
    cout<<"Sorted array: ";
    printarray(arr);
    return 0;
}