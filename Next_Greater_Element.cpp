#include <bits/stdc++.h>
using namespace std;
vector <int> nextGreaterEle(vector <int> &num){
    int n = num.size();
    vector <int> ans(n , -1);
    stack <int> st;
    st.push(num[n-1]);
    int i=n-2;
    while(i>=0){
        while(!st.empty() && st.top() <= num[i]){
            st.pop();
        }

        if(st.size()) ans[i] = st.top();

        st.push(num[i]);
        i--;
    }
    return ans;
}
int main() {
    vector <int> nums = {6, 8, 0, 1, 3};
    nums = nextGreaterEle(nums);
    for(int ele : nums) cout<<ele<<" ";
    return 0;
}
