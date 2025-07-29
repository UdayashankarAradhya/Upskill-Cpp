#include<iostream>
using namespace std;
void printUnique(int arr[], int n){
    if(n<=0) return;
    bool isunique;
    for(int i=0;i<n;i++){
        isunique=true;
        for (int j = 0; j < n; j++){
            if(i!= j && arr[j]==arr[i]){
               
                isunique=false;
             
            
        }
        }

        
        if(isunique==true){
            cout<<arr[i]<<" ";

        }
        
 
    }
    cout<<endl;
 
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
        cout<<"Unique elements in the array are: ";
        printUnique(arr,n);
        cout<<endl;
        return 0;   
    }
}
