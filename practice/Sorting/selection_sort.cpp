#include<iostream>
#include<vector>
using namespace std;
void selection_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        } 
        swap(arr[i],arr[min_index]);
    }
}
void printarray(const vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> arr;
    int n, element;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>element;
        arr.push_back(element);
    }
    selection_sort(arr);
    cout<<"Sorted array elements: ";
    printarray(arr);
    return 0;


}