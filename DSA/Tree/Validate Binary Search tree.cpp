class Solution {
public:
    bool valid = true;
    void isValid(TreeNode* root,long long i,long long j) {
        if(root == NULL)
            return;
        if(root->val >i && root->val<j)
        {
            isValid(root->left,i,root->val);
            isValid(root->right,root->val,j);
            
        }
        else
        {
            
            valid = false;
            return;
        }
    }
    bool isValidBST(TreeNode* root) {
        isValid(root, LLONG_MIN, LLONG_MAX);
        return valid;
            
    }
};