#include<iostream>
#include<string>
using namespace std;

string title_case(string text) {
    bool inword = false;
    for(int i=0;i< text.length(); i++) {
        if(!isspace(text[i])){
            if(!inword) {
                text[i]= toupper(text[i]);
                inword = true;

            }
        }else{
            inword = false;
        }
    }
    return text;
}
int main() {
    string text;
    cout << "Enter a text: ";
    getline(cin, text);
    string result = title_case(text);
    cout << "Text in title case: " << result << endl;
    return 0;
}