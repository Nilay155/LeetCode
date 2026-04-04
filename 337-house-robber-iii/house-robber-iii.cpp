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
    unordered_map<TreeNode*,unordered_map<bool,int>> dp;
    int maximumTheft(TreeNode* root,bool flag) {
        if(root == nullptr) return 0;
        if(dp.count(root) && dp[root].count(flag)) return dp[root][flag];

        int rob = 0;
        if(flag) 
            rob = root -> val + maximumTheft(root -> left,false) + maximumTheft(root -> right,false);
        int noRob = maximumTheft(root -> left,true) + maximumTheft(root -> right,true);
        return dp[root][flag] = max(rob,noRob);
    }
public:
    int rob(TreeNode* root) {
        return maximumTheft(root,true);
    }
};