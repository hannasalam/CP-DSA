class Solution {
public:
    int sum = 0;
    int findNumCecodings(string s,int si, vector<int> &r)
    {
        if(r[si]!=-1) return r[si];
        if(s[si]=='0') return r[si]=0;
        int res = findNumCecodings(s,si+1,r);
        if(si<s.size()-1 && (s[si]=='1' || (s[si]=='2' && s[si+1]<'7')))  res+= findNumCecodings(s,si+2,r);
        
       return r[si]=res;
    }
    int numDecodings(string s) {
        vector<int> r(s.size()+1,-1);
        r[s.size()]=1;
        return findNumCecodings(s, 0,r);
    }
};