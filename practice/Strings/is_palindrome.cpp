#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool palindrome_check(string word){
    string str=word;
    reverse(str.begin(),str.end());
    return str==word;

}
int main(){
    string word;
    cout<<"Enter a word: ";
    cin>>word;
    if(palindrome_check(word)){
        cout<<"The word is Palindrome."<<endl;
    }
    else{
        cout<<"Not a Palindrome."<<endl;

    }
    return 0;
    }
