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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr) return root;
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }
        // Level Order traversal
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()) {

            auto [node,d] = q.front(); q.pop();

            if(d == depth - 1) {
                TreeNode* leftSubtree = node -> left;
                TreeNode* rightSubtree = node -> right;
                node -> left = new TreeNode(val);
                node -> right = new TreeNode(val);
                node -> left -> left = leftSubtree;
                node -> right -> right = rightSubtree;
                continue;
            }

            if(node -> left) q.push({node -> left,d + 1});
            if(node -> right) q.push({node -> right,d + 1});
        }
        return root;
    }
};