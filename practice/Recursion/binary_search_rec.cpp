#include<iostream>
using namespace std;
int binary_search(int arr[], int target, int low, int high) {
    if(low > high) {
        return -1;
    }
    int mid=low + (high-low)/2;
    if(arr[mid] == target) {
        return mid;}
    else if(arr[mid]> target) {
            return binary_search(arr, target, low, mid-1);
        }
    else {
            return binary_search(arr, target , mid+1, high);
        }
    }
int main() {
    int n, target;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;  
    int arr[n]; 
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }   
    cout<<"Enter the target element to search: ";
    cin>>target;
    int result = binary_search(arr, target, 0, n-1);
    if(result != -1) {
        cout<<"Element found at index: " << result << endl;
    } else {
        cout<<"Element not found in the array." << endl;
    }
    return 0;          
}