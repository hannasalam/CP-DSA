class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int s = 0, f = n-1;
        int maxArea = 0;
        while(s<f)
        {
            maxArea = max(maxArea,min(h[s],h[f])*(f-s));
            if(h[s]<h[f]) s++;
            else f--;
        }
        return maxArea;
    }
};
//two pointer approach


int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i) continue;
                if(height[j]>=height[i])
                {
                    maxArea = max(maxArea, height[i]*abs(i-j));
                }
            }
        }
        return maxArea;
        
    }
//bruteforce, got tle