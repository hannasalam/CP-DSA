class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //find the range in which the number is min
        //the number of subsqueunces = rightIndex - minIndex * minIndex - leftIndex
        long long MOD = 1000000007;
        stack<long long> st;
        long long ans = 0;
        for(int i=0;i<=arr.size();i++){
            while(!st.empty() and (i==arr.size() or arr[i]<=arr[st.top()])){
                auto top = st.top();
                st.pop();
                long long li = st.empty()?-1:st.top();
                long long c = top;
                long long count = (i-c)*(c-li) % MOD;
                ans+= (arr[c]* count)%MOD;
                ans%=MOD;
            }
            st.push(i);
        }
        return (int)ans;
    }
};