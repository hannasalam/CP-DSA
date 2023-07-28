class Solution {
public:
    struct Node{
        Node *bit[2];
        bool contains(int i){
            if(bit[i]!=nullptr) return true;
            return false;
        }
        void put(int i){
            bit[i] = new Node();
        }
        Node* next(int b){
            return bit[b];
        }
    };
    class Trie{
        private: 
            Node *root;
        public:
            Trie(){
                root = new Node();
            }
            void insert(int num){
                auto temp = root;
                for(int i=31;i>=0;i--){
                    int b = (num & (1 << i))!= 0 ? 1 : 0;
                    if(!temp->contains(b)){
                        temp->put(b);
                    }
                    temp = temp->next(b);
                }
            }
            int maxor(int num){
                auto temp = root;
                int max_ans = 0;
                for(int i=31;i>=0;i--){
                    int b = (num & (1 << i)) != 0 ? 1 : 0;
                    int a = (b == 1) ? 0 : 1;
                    if(temp->contains(a)){
                        max_ans = max_ans|(1<<i);
                        temp = temp->next(a);
                    }
                    else{
                        temp = temp->next(b);
                    }
                }
                return max_ans;
            }
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int i=0;i<nums.size();i++){
            t.insert(nums[i]);
        }
        int ans = 0;
        for(auto i:nums){
            ans = max(t.maxor(i),ans);
        }
        return ans;
    }
};