class Solution {
public:
    bool same = true;
    void checkSameTree(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)
        {
            return;
        }
        else if(p==NULL || q==NULL)
        {
            same = false;
            return;
        }
        else if(p->val!= q->val)
        {
            same = false;
            return;
        }
        checkSameTree(p->left,q->left);
        checkSameTree(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        checkSameTree(p,q);
        return same;
    }
};