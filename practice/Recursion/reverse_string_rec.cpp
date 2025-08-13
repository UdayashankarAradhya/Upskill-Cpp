#include<iostream>
using namespace std;
string reverse_string(string str) {
    if(str.size()<=1) return str;
    return reverse_string(str.substr(1))+str[0];

}
int main() {
    string word;
    cout<<"Enter a string: ";
    cin>>word;
    string reversed= reverse_string(word);
    cout<<"Reversed string is: "<<reversed<<endl;
    return 0; 
}