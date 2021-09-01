Method 1(Hashmaps):

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        int max = 0, maxe;
        for(auto it:mp)
        {
            if(it.second>max)
            {
                max = it.second;
                maxe = it.first;
            }
        }
        return maxe;
    }
};

Method 2(Boyer Moore Majority Vote Algorithm):

int majorityElement(vector<int>& nums) {
        int candidate = INT_MIN, count = 1;
        for(auto i:nums)
        {
            if(candidate!=i) count--;
            else count++;
            if(count==0)
            {
                count++;
                candidate = i;
            }
            
        }
        return candidate;
    }