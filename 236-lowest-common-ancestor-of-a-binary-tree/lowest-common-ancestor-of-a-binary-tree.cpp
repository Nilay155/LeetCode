/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* LCA = nullptr;
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q) {
        if(root == nullptr) return nullptr;
        
        TreeNode* left = lca(root -> left,p,q);
        TreeNode* right = lca(root -> right,p,q);

        if(root -> val == p -> val || root -> val == q -> val) {
            return root;
        }

        if(left && right) {
            return root;
        } else if(left || right) {
            return left == nullptr ? right : left;
        } else {
            return nullptr;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
        // return LCA;
    }
};