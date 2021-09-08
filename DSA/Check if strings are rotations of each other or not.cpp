    bool areRotations(string s1,string s2)
    {
        if(s1.size()!=s2.size()) return 0;
        queue<int> f;
        for(auto i:s1)
            f.push(i);
        queue<int> e;
        for(auto i:s2)
            e.push(i);
        int k = s2.size();
        while(k--)
        {
            char ch= e.front();
            e.pop();
            e.push(ch);
            if(e==f)
                return 1;
        }
        return 0;
    }