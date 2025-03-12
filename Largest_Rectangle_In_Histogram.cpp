#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
         vector <int> pre_smaller_idx(heights.size(),-1);
         vector <int> next_smaller_idx(heights.size(),heights.size());
         stack <int> st;
         st.push(0);
         for(int i=1;i<heights.size();i++){
            while(st.size()>0 && heights[st.top()]>=heights[i]) st.pop();
            if(st.size()!=0) pre_smaller_idx[i]=st.top();
            st.push(i);
        }
    
         stack <int> gt;
         gt.push(heights.size()-1);
         for(int i=heights.size()-2;i>=0;i--){
            while(gt.size()>0 && heights[gt.top()]>=heights[i]) gt.pop();
            if(gt.size()!=0) next_smaller_idx[i]=gt.top();
            gt.push(i);
         }
    
         int area=0;
         for(int i=0;i<heights.size();i++){
            int temp=heights[i]*(next_smaller_idx[i]-pre_smaller_idx[i]-1);
            area=max(area,temp);
         }
         return area;
}
int main() {
    vector <int> height = {2,1,5,6,2,3};
    cout<<"Max Rectangle Area = "<<largestRectangleArea(height)<<endl;
    return 0;
}
