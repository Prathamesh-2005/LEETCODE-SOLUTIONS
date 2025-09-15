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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> dq;
        dq.push(root);
        bool reverseFlag = false;

        while(!dq.empty()){
            int size = dq.size();
            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* temp = dq.front(); dq.pop();
                level.push_back(temp->val);
                if(temp->left) dq.push(temp->left);
                if(temp->right) dq.push(temp->right);
            }

            if(reverseFlag)
                std::reverse(level.begin(), level.end());

            reverseFlag = !reverseFlag;
            ans.push_back(level);
        }
        return ans;
    }
};