class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k% n;
        int temp = nums[0], pos = 0, st;
        int j=0;
        for(int i=0;i<n;i++)
        {
            pos = (pos+k)%n;
            
            st = nums[pos];
            nums[pos] = temp;
            temp = st;
            
            if(pos==j)
            {
                pos = ++j;
                if(pos > nums.size()-1)
                    return;
                temp = nums[pos];
            }
            
        }
        
        
        
    }
};