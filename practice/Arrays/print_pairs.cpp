#include<iostream>
#include<vector>
using namespace std;
void printpairs(vector<int> &arr){
    int n=arr.size();
    if(n<=0) return;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<"("<<arr[i]<<","<<arr[j]<<")"<<" "; 

        }
    }cout<<endl;
    
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
        vector<int> arr(n);
        cout<<"Enter the elements of the array: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"Pairs in the array are: ";
        printpairs(arr);
        cout<<endl;
        return 0;   
    }
}