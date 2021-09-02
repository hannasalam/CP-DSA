vector<int> majorityElement(vector<int>& nums) {
        int c1, ct1, ct2=0, c2 = INT_MIN;
        c1 = nums[0];
        ct1 = 1;
        //if(nums.size()<3) return nums;
        for(int i =1;i<nums.size();i++)
        {
            if(nums[i]==c1)
            {
                ct1++;
                
            }     
            else if(nums[i]==c2)
            {
                ct2++;
            }
            else if(ct1<=0)
            {
                c1 = nums[i];
                ct1 = 1;
            }
            else if(ct2<=0)
            {
                c2 = nums[i];
                ct2 = 1;
            }
            else
            {
                ct2--;
                ct1--;
            }
            
        }
        //cout<<c1<<" "<<c2;
        ct1 = 0;
        ct2 = 0;
        for(auto i:nums)
        {
            if(i==c1) ct1++;
            if(i==c2) ct2++;
        }//recheck if the numbers got are correct.
        vector<int> ans;
        //cout<<ct1<<" "<<ct2;
        if(ct1>nums.size()/3) ans.push_back(c1);
        if(ct2>nums.size()/3) ans.push_back(c2);
        return ans;
        
    }