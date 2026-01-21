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
    pair<int,int> dfs(TreeNode* root,int &ans) {
        if(root == nullptr) return {0,0};

        auto [leftSubtree,leftCount] = dfs(root -> left,ans);
        auto [rightSubtree,rightCount] = dfs(root -> right,ans);
        int totalValue = root -> val + leftSubtree + rightSubtree;
        int average = totalValue / (leftCount + rightCount + 1);

        if(average == root -> val) ans += 1;

        return {totalValue,leftCount + rightCount + 1};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};