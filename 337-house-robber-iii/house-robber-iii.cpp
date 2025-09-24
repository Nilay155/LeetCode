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
private:
    // int maxi = INT_MIN;
    unordered_map<TreeNode*,int> dp;
    int f(TreeNode* root) {
        if(root == nullptr) return 0;
        if(dp.find(root) != dp.end()) return dp[root];

        int pick = root -> val; 
        if(root -> left != nullptr)
            pick += f(root -> left -> left) + f(root -> left -> right);
        if(root -> right != nullptr)
            pick += f(root -> right -> left) + f(root -> right -> right);

        int notPick = f(root -> left) + f(root -> right);
        return dp[root] = max(pick,notPick);
    }
public:
    int rob(TreeNode* root) {
        return f(root);
    }
};