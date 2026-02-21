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
    typedef long long ll;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        priority_queue<ll>mx;
        int lev=0;
        while(!q.empty())
        {
            int n=q.size();
            ll sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;

                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            mx.push(sum);
            lev++;
        }
        ll ans=0;
        if(lev<k)
        {
            return -1;
        }
        while(k--)
        {
            ans=mx.top();
            mx.pop();
        }
        return ans;
    }
};