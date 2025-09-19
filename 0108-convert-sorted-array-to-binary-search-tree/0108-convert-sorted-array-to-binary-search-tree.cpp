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
    TreeNode* solve(int i,int j,vector<int>& nums)
    {
        int n=nums.size();
        if(i>j)
        {
            return nullptr;
        }

        int mid=(i+j)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        TreeNode* left=solve(i,mid-1,nums);
        TreeNode* right=solve(mid+1,j,nums);

        root->left=left;
        root->right=right;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return nullptr;
        }
        TreeNode* root=solve(0,n-1,nums);
        return root;
    }
};