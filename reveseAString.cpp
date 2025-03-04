#include <bits/stdc++.h>
using namespace std;
string reverseStr(string &s){
    stack <char> st;
    int i=0;
    int len  = s.length();
    while(i<len){
      st.push(s[i]);
      i++;
    }
    s="";
    while(!st.empty()){
        s+=st.top();
        st.pop();
    }
    return s;
}
int main() {
    string s="engineer";
    cout<<reverseStr(s)<<endl;
    return 0;
}