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
    long long ans=0;
    long long sum=0;
    long long total_sum=0;
    int mod=1e9+7;
    
    long long total(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        long long left=total(root->left);
        long long right=total(root->right);
        long long curr=root->val+left+right;

        return curr;
    }
    long long find(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        long long left=find(root->left);
        long long right=find(root->right);
        long long curr=root->val+left+right;

        long long remain=total_sum-curr;
        ans=max(ans,remain*curr);

        return curr;
    }
    int maxProduct(TreeNode* root) {
        total_sum=total(root);
        find(root);
        return ans%mod;
    }
};