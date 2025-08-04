#include<iostream>
#include<string>
using namespace std;

string removeDuplicates(string word) {
    string newWord="";
    int freq[256] ={0};
    for(char c: word) {
        if(isalpha(c)){
            if(freq[c]==0){
                newWord += c;
                freq[c]++;
            }
        }
    }
    return newWord;
}
int main() {
    string word;
    cout<<"Enter a word: ";
    cin>>word;
    string result = removeDuplicates(word);
    cout<<"Word after reomoving Duplicates: "<<result<<endl;
    return 0;
}