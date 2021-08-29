class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> gr;
        unordered_map<int,int> map;
        gr.push(nums2[nums2.size()-1]);
        map[nums2[nums2.size()-1]] = -1;
        for(int i=nums2.size()-2;i>=0;i--)
        {
            while(true)
            {
                if(gr.empty())
                {
                    map[nums2[i]] = -1;
                    gr.push(nums2[i]);
                    break;
                }
                else if(gr.top()>nums2[i])
                {
                    map[nums2[i]] = gr.top();
                    gr.push(nums2[i]);
                    break;
                }
                else
                {
                    gr.pop();
                }
            }
        }
        for( auto i: nums1)
        {
            ans.push_back(map[i]);
        }
        return ans;
        
    }
};