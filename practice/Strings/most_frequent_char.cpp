#include<iostream>
#include<string>
using namespace std;
char most_freq_char(string word) {
    int freq[256] = {0};
    char maxChar = '\0';
    int maxCount= 0;
    for(char  c: word){

        if(isalpha(c)){
            freq[c]++;
            if(freq[c]>maxCount){
                maxCount= freq[c];
                maxChar =c;

            }
        }
    }
    return maxChar;
}
int main() {
    string word;
    cout<<"Enter a word: ";
    cin>>word;
    char result = most_freq_char(word);
    if(result != '\0') {
        cout<<"Most frequent character: "<< result << endl;
    } else {
        cout<<"No alphabetic characters found."<<endl;
    }
    return 0;
}
