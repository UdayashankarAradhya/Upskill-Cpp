#include<iostream>
#include<string>
using namespace std;
string to_uppercase(string word) {
    string upperWord = "";
    for(char &c: word) {
        if(isalpha(c)){
            upperWord += toupper(c);
            
        }
        else{
            upperWord += c;
        }
    }
    return upperWord;
}
int main(){
    string word;
    cout<<"Enter a word: ";
    cin>>word;
    string upperWord = to_uppercase(word);
    cout<<"Uppercase word: "<< upperWord << endl;
    return 0;
}
