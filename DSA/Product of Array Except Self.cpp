Approach 1 O(N) time and O(N) space:

vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> frwd;
        vector<int> back;
        int f=1, y=1;
        for(int i=0,j=nums.size()-1;i<nums.size();i++,j--)
        {
            cout<<f<<" ";
            frwd.push_back(f);
            back.push_back(y);
            f*= nums[i];
            y*= nums[j];
        }
        cout<<"\n";
        vector<int> ans;
        reverse(back.begin(),back.end());
        for(int i=0;i<nums.size();i++)
        {
            
            ans.push_back(frwd[i]*back[i]);
        }
        return ans;
    }

Approach 2 O(N) time and O(1) space:

vector<int> productExceptSelf(vector<int>& nums) {
        int f=1, y=1;
        vector<int> ans(nums.size(),1);
        for(int i=0,j=nums.size()-1;i<nums.size();i++,j--)
        {
            ans[i]*=f;
            f*=nums[i];
            ans[j]*=y;
            y*= nums[j];
        }
        cout<<"\n";
        return ans;      
        
    }//technically, approach is the same, just removed the extra space