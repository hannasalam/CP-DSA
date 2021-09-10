    int check(int a, vector<int> tops, vector<int> bottoms)
    {
        int s = 0;
        for(int i = 0;i< tops.size();i++)
        {
            if(tops[i]!=a)
            {
                if(bottoms[i]!=a)
                {
                    return INT_MAX;
                }
                else
                    s++;
            }
        }
        return s;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a = check(tops[0],tops,bottoms);
        int b = check(bottoms[0],tops,bottoms);
        int c = check(tops[0],bottoms,tops);
        int d = check(bottoms[0],bottoms,tops);
        int x = min(a,min(b,min(c,d)));
        if(x==INT_MAX) return -1;
        return x;
    }