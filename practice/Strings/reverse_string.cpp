#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string reverse_string(string word) {
    string reversedWord = "";
    reverse(word.begin(), word.end());
    return word;
}
int main() {
    string word;
    cout<<"Enter a Word: ";
    cin>>word;
    string reversedWord;
    reversedWord = reverse_string(word);
    cout<<"Reversed word: "<<reversedWord << endl;
    return 0;

}