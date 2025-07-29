#include<iostream>
using namespace std;
void intersectionOfTwoArrays(int arr1[],int arr2[], int n, int m){
    if(n<=0 || m<=0) return;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i]==arr2[j]){
                cout<<"Intersection of the two arrays: "<<arr1[i]<<" ";

            }

        }
    }
    cout<<endl;
}
int main(){
    cout<<"Enter the size of the first array: ";
    int n;
    cin>>n;
    if(n<=0){
        cout<<"Enter a valid size greater than 0."<<endl;
        return 0;
    }
    int arr1[n];
    cout<<"Enter the elements of the first array: ";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    cout<<"Enter the size of the second array: ";
    int m;
    cin>>m;
    if(m<=0){
        cout<<"Enter a valid size greater than 0."<<endl;
        return 0;
    }
    int arr2[m];
    cout<<"Enter the elements of the second array: ";
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    intersectionOfTwoArrays(arr1, arr2, n, m);
    
    return 0;
}