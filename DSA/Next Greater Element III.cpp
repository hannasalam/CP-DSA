class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int flag = 0;
        int i=s.size()-2;
        for(;i>=0&&s[i]>=s[i+1];i--){}//finds the first decreasing element
        if(i==-1)
            return -1;
        reverse(s.begin()+i+1,s.end());
        //both sort and reverse works. But reverse is more efficient
        // cout<<s;
        
        for(int j = i+1;j<s.size();j++)
        {
            if(s[j]>s[i])
            {
                swap(s[i],s[j]);
                break;
            }
        }//swaps it with the first bigger element
        long next = stol(s);
        return next == n || next > INT_MAX ? -1 : next; // to prevent int overflow
        
        //return -1;
        
     
    }
};