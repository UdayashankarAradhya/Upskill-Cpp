#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr, int start, int mid, int end){
    int n1=mid-start+1;
    int n2=end-mid;
    vector<int> L(n1), R(n2);
    for(int i=0;i<n1; i++){
        L[i]=arr[start+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }
    int k=start;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int start, int end){
    if(start>=end)
    return;
    int mid=start+(end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
int main(){
    vector<int> arr;
    int n;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    int element;
    for(int i=0;i<n;i++){
        cin>>element;
        arr.push_back(element);
    }
    mergeSort(arr,0,n-1);
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}