int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int child = 0;
        for(int loop=0;loop<s.size();loop++)
        {
            if(child>=g.size())
                break;
            if(s[loop]>=g[child])
            {
                child++;
            }
        }
        return child;
    }