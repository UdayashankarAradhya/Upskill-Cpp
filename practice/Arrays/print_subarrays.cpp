#include<iostream>
#include<vector>
using namespace std;
void printSubArrays(vector<int> &arr){
    int n=arr.size();
    for(int start=0;start<n;++start){
        for(int end=start; end<n;++end){
            cout<<"{";
            for(int i=start;i<=end; ++i){
                cout<<arr[i];
                if(i<end){
                    cout<<" ";
                }

            }
            cout<<"}"<<endl;
        }
        

    }
    
    
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
        cout<<" Sub arrays in the array are: ";
        printSubArrays(arr);
        cout<<endl;
        return 0;   
    }
}