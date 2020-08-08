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
        if(n == 0)
            return {};
        
        return genTrees(1,n);
    }
};