#include<iostream>
#include<string>
#include<utility>
using namespace std;

pair<int, int> count_vowels(string word) {
    int vCount = 0; int cCount = 0;
    string vowels="aeiouAEIOU";
    for(char c : word) {
        if(vowels.find(c)!= string::npos){
            vCount++;
        }
        else if(isalpha(c)) {
            cCount++;
        }
        }
        return{vCount, cCount};
    }


int main() {
    string word;
    cout<<" Enter a word: ";
    cin>>word;
    pair<int, int> result= count_vowels(word);
    cout<<"Number of vowels: "<< result.first << endl;
    cout<<"Number of consonants: "<< result.second << endl;
    return 0;

}
