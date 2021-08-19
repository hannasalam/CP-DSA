vector<int> singleNumber(vector<int>& x) {
           long long int xr=0, n= x.size(),lsb;
        for(auto h:x)
        {
            xr^=h;
        }
        lsb = xr&(-xr);
        int a=0,b=0;
        for(auto i:x)
        {
            if(i&lsb) a^=i;
            else b^=i;
        }

        return {a,b};
    }
