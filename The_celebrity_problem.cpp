#include <bits/stdc++.h>
using namespace std;

    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> st;
        
        // Step 1: Push all people onto the stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }
        
        // Step 2: Eliminate non-celebrities
        while (st.size() > 1) {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();
            
            if (mat[A][B] == 1) {
                // A knows B, so A cannot be a celebrity
                st.push(B);
            } else {
                // A doesn't know B, so B cannot be a celebrity
                st.push(A);
            }
        }
        
        // Step 3: Verify the remaining candidate
        int candidate = st.top();
        
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // Candidate should not know anyone, and everyone should know candidate
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                    return -1;
                }
            }
        }
        
        return candidate;
    }
    
int main() {
    vector <vector <int>> num = {{1,1,0} , {0,1,0} , {0,1,1}};
    cout<<celebrityIndex(num)<<endl;
    return 0;
}
