#include<iostream>
#include<vector>
using namespace std;
vector<int> findPrefixSum(vector<int> &arr){
    int n=arr.size();
    
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0]; 
    for(int i=1; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    return prefixSum;
}
int main() {
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    if(n<=0) {
        cout<<"Enter a valid size greater than 0."<<endl;
        return 0;
    }
    else {
        vector<int> arr(n);
        cout<<"Enter the elements of the array: ";
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        vector<int> result = findPrefixSum(arr);
        cout<<"Prefix sum of the array is: ";
        for(int i=0; i<n; i++) {
            cout<<result[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
}