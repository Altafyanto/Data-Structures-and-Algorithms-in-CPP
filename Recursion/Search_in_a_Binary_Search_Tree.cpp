//Question:- (https://leetcode.com/explore/featured/card/recursion-i/251/scenario-i-recurrence-relation/3233/)

class Solution
{
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        //if Root is null,that means such node doesn't exist.
        if(!root)
            return NULL;
            
        //if root val is equal to val means required node is found
        if(root->val == val)
            return root;
         //if root val is greater than val means required node mat be on the left subtree
        else if(root->val > val)
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);
    }
};
