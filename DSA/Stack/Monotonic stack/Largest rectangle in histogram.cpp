class Solution {
public:
    vector<int> prevGreatestElement(vector<int>&v){
        vector<int> ans(v.size());
        stack<int> st;
        st.push(-1);
        for(int i=0;i<v.size();i++){
            while(st.top()!=-1 and v[st.top()]>=v[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>&v){
        vector<int> ans(v.size());
        stack<int> st;
        st.push(v.size());
        for(int i=v.size()-1;i>=0;i--){
            while(st.top()!=v.size() and v[st.top()]>=v[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        auto next = nextGreaterElement(heights);
        auto prev = prevGreatestElement(heights);
        int ans = 0;
        for(int i=0;i<heights.size();i++){
            int h = heights[i];
            int n = next[i];
            int p = prev[i];
            // cout<<h<<"\t"<<n<<"\t"<<p<<"\n";
            ans = max(ans, h*(n-p-1));
        }
        return ans;
    }
};