// Question:- (https://leetcode.com/explore/featured/card/recursion-i/253/conclusion/2384/)
/*
I start by noting that 1..n is the in-order traversal for any BST with nodes 1 to n. So if I pick i-th node as my root,
the left subtree will contain elements 1 to (i-1), and the right subtree will contain elements (i+1) to n. 
I use recursive calls to get back all possible trees for left and right subtrees and combine them in all possible ways with the root.
*/
class Solution
{
public:
    vector<TreeNode*> genTrees(int start,int end)
    {
        vector<TreeNode*>v;

        if(start > end)
        {
            v.push_back(NULL);
            return v;
        }

        for(int i=start; i<= end; i++)
        {
            for(auto left : genTrees(start,i-1))
            {
                for(auto right : genTrees(i+1,end))
                {
                    TreeNode* root = new TreeNode(i);
                    root -> left = left;
                    root -> right = right;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n)
    {
        //if n is 0 then no tree can be generated.
        if(n == 0)
            return {};
        
        return genTrees(1,n);
    }
};
