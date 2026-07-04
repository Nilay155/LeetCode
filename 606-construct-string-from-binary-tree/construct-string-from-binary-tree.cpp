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
    string constructStringFromTree(TreeNode* root) {
        if(root == nullptr)
            return "";
        
        string node = to_string(root -> val);
        string left = constructStringFromTree(root -> left);
        string right = constructStringFromTree(root -> right);

        if(left.empty() && right.empty()) {
            return node;
        } else if(right.empty()) {
            return node + "(" + left +")";
        } else if(left.empty()) {
            return node + "()" + "(" + right + ")";
        } else {
            return node + "(" + left + ")" + "(" + right + ")";
        }
    }
public:
    string tree2str(TreeNode* root) {
        return constructStringFromTree(root);
    }
};