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
    int diameter(TreeNode* root,int &maxDiameter) {
        if(root == nullptr) return 0;

        int left = 1 + diameter(root -> left,maxDiameter);
        int right = 1 + diameter(root -> right,maxDiameter);

        maxDiameter = max(maxDiameter,left + right - 2);
        return max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        diameter(root,maxDiameter);
        return maxDiameter;
    }
};