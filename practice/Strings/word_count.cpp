#include<iostream>
#include<string>
using namespace std;

int count_words(string text) {
   bool inword=false;
    int count=0;
    for(char c: text){
        if(!isspace(c)){
            if(!inword){
                count++;
                inword=true;
            }
        
            
        }
        else{
            inword=false;
        }
    }
    return count;
}
int main(){
    string text;
    cout<<"Enter a text: ";
    getline(cin, text);
    int word_count= count_words(text);
    cout<<"Number of words in the text: "<<word_count<<endl;
    return 0;

}