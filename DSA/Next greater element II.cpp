Approach 1(Brute Force):

 vector<int> ans;
        for(auto i:nums1)
        {
            int flag = 0,red = 0;
            for(auto j:nums2)
            {
                if(j == i)
                {
                    flag = 1;
                }
                if(flag==1)
                {
                    if(j>i) 
                    {
                        ans.push_back(j);
                        red =1;
                        break;
                    }
                }
            }
            if(red!=1)
            {
                ans.push_back(-1);
            }
        }
        return ans;


Approach 2(Optimized):
//Optimised but not clean :p

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> gr;
        for(int i=2*n-1;i>=0;i--)
        {
            int x = i%n;
            while(true)
            {
                if(gr.empty())
                {
                    ans[x] = -1;
                    gr.push(nums[x]);
                    break;
                }
                else if(gr.top()>nums[x])
                {
                    ans[x] = gr.top();
                    gr.push(nums[x]);
                    break;
                }
                else
                {
                    gr.pop();
                }
            }
            
        }
         
        return ans;
       
    }
