    int maximumSwap(int num) {
        string s = to_string(num);
        int maxi = s.size()-1;
        int lefti = -1,rigi = -1;
        for(int i = s.size()-2;i>=0;i--)
        {
            if(s[i]>s[maxi])
                maxi = i;
            if(s[i]<s[maxi])
            {
                lefti = i;
                rigi = maxi;
            }
                
        }
        if(lefti == -1) return num;
        swap(s[rigi],s[lefti]);
        int x;
        stringstream f(s);
        f>>x;
        return x;
    }