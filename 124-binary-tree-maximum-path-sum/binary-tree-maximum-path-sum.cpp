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
    int maxPath = INT_MIN;
    int findMaxPath(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = findMaxPath(root -> left);
        int right = findMaxPath(root -> right);

        int totalSum = max({root -> val, left + root -> val , right + root -> val,
            left + right + root -> val});
        
        maxPath = max(maxPath,totalSum);

        return max({left + root -> val, right + root -> val, root -> val});
    }
public:
    int maxPathSum(TreeNode* root) {
        findMaxPath(root);
        return maxPath;
    }
};