#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution{
    public:
        bool isValid(string str){
            stack<char>st;
            for(char c: str){
                if(c=='{' || c=='[' || c=='('){
                    st.push(c);

                }
                else if(c=='}' || c==']' || c==')'){
                    if(st.empty()){
                        return false;

                    }
                    char top=st.top();
                    
                    if((c=='}' && top!='{') || (c==']' && top!='[') || (c=='(' && c==')')){
                        return false;
                    }
                    
                    st.pop();
                    
                }
                
            }
            return st.empty();

        }
};

int main() {
    Solution mySolution;

    // --- Test Cases ---
    string s1 = "()[]{}";
    string s2 = "([{}])";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "{[}";
    string s6 = "{{";
    string s7 = ")";

    cout << "'" << s1 << "'" << " is valid? " << (mySolution.isValid(s1) ? "Yes" : "No") << endl;
    cout << "'" << s2 << "'" << " is valid? " << (mySolution.isValid(s2) ? "Yes" : "No") << endl;
    cout << "'" << s3 << "'" << " is valid? " << (mySolution.isValid(s3) ? "Yes" : "No") << endl;
    cout << "'" << s4 << "'" << " is valid? " << (mySolution.isValid(s4) ? "Yes" : "No") << endl;
    cout << "'" << s5 << "'" << " is valid? " << (mySolution.isValid(s5) ? "Yes" : "No") << endl;
    cout << "'" << s6 << "'" << " is valid? " << (mySolution.isValid(s6) ? "Yes" : "No") << endl;
    cout << "'" << s7 << "'" << " is valid? " << (mySolution.isValid(s7) ? "Yes" : "No") << endl;

    return 0;
}