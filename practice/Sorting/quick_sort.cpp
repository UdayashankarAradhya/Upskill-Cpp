#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int start, int end){
    int index=start-1;
    int pivot=arr[end];
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            index++;
            swap(arr[index], arr[j]);
        }
    }
    index++;
    swap(arr[index],arr[end]);
    return index;
}
void quickSort(vector<int> &arr, int start, int end){
    if(start>=end){
        return;
    }
    int pvt=partition(arr,start,end);
    quickSort(arr,start,pvt-1);
    quickSort(arr,pvt+1,end);

}
int main(){
    vector<int> arr;
    int n;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    cout<<"ENter the array elements: ";
    int element;
    for(int i=0;i<n;i++){
        cin>>element;
        arr.push_back(element);
    }
    quickSort(arr,0, n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}