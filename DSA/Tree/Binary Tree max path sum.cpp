class Solution {
    
public:
    int maxS = INT_MIN;
    int maxSum(TreeNode* curr) {
        int sum = 0;
        if(curr==NULL) return 0;
        int ls = maxSum(curr->left);
        int rs = maxSum(curr->right);
        int maxlr = max(ls,rs);
        int maxOne = max(curr->val,curr->val+maxlr);
        int maxAll =  max(maxOne, curr->val+ls+rs);
        maxS = max(maxS,maxAll);
        return maxOne;
    }
    int maxPathSum(TreeNode* curr) {
        int s = maxSum(curr);
        maxS = max(maxS,s);
        return maxS;
    }
};