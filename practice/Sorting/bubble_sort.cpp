#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bubblesort(vector<int>& arr) {
    int n= arr.size();
    bool swapped;
    for(int i=0;i<n-1;i++) {
        swapped=false;
        for(int j=0;j<n-i-1;j++) {
            if(arr[j+1]<arr[j]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) {
            break; 
    }
}
}
int main() {
    vector<int> arr;
    int n, element;
    cout<< "Enter number of elements: ";
    cin>>n;
    cout<< "Enter elements: ";
    for(int i=0;i<n;i++) {
        cin>>element;
        arr.push_back(element);
    }
    bubblesort(arr);
    cout<< "Sorted array: ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    return 0;
}
