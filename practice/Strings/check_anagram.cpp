#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool check_anagram(string word1, string word2) {
    if(word1.length() != word2.length()) {
        return false;
        
    }
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    return word1 == word2;

}
int main(){
    string word1, word2;
    cout<< "Enter first word: ";
    cin>>word1;
    cout<<"Enter second word: ";
    cin>>word2;
    if(check_anagram(word1, word2)) {
        cout<<" The words are anagrams."<<endl;
    } else {
        cout<<" The words are not anagrams."<<endl;
    }
    return 0;
    }
