#include<iostream>
using namespace std;
int main(){
    
    int num=3;
    for(int i=0; i<num; i++){
        char ch='A'+i;
        for(int j=i+1;j>0;j--){
            cout<<ch<<" ";
            ch--;
        }
        cout<<endl;

    }
}