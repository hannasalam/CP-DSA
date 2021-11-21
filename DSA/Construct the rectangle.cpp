vector<int> constructRectangle(int area) {
        int m = sqrt(area);
        if(area==0)
        {
            return {0,0};
        }
        int ans = 1;
        for(int i=m;i>0;i--)
        {
            int n = area%i;
            if(n == 0)
            {
               return {area/i, i};
            }
        }
        return {0,0};
    }