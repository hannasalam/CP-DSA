    int numTimesAllBlue(vector<int>& light) {
        int count = 0;
        int maxi = 0;
        for(int i=0;i<light.size();i++)
        {
            maxi = max(maxi , light[i]);
            if(maxi == i+1)
                count++;
        }
        return count;
        
        
    }