/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int& ans)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);

        int temp=max(root->val,max(l,r)+root->val);
        int res=max(temp,l+r+root->val);
        ans=max(ans,res);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};