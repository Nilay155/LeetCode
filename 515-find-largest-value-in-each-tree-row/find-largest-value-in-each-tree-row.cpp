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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL) return {};
        
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        int maxi = INT_MIN;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            if(node == NULL) {
                if(!q.empty()) q.push(NULL);
                ans.push_back(maxi);
                maxi = INT_MIN;
                continue;
            }
            maxi = max(maxi,node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return ans;
    }
};