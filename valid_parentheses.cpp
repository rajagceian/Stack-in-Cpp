#include <bits/stdc++.h>
using namespace std;
bool isBalanced(string &s){
    int n = s.length();
    stack <char> st;
    int i=0;
    while(i<n){
        if(!st.empty() && ((st.top()=='(' && s[i]==')') || (st.top()=='[' && s[i]==']') || (st.top()=='{' && s[i]=='}'))){
           st.pop(); 
        }
        else st.push(s[i]);
        i++;
    }
    return st.size() == 0;
}
int main() {
    string s = "(()())";
    cout<<isBalanced(s)<<endl;
    return 0;
}