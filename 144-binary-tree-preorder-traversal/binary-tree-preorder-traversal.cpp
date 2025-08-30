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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* node = root;

        while(node != nullptr) {

            preorder.push_back(node -> val);

            if(node -> left == nullptr) {
                node = node -> right;
            } else {
                TreeNode* predecessor = node -> left;

                while(predecessor -> right != nullptr && predecessor -> right != node) {
                    predecessor = predecessor -> right;
                }
                if(predecessor -> right == node) {
                    preorder.pop_back();
                    predecessor -> right = nullptr;
                    node = node -> right;
                } else {
                    predecessor -> right = node;
                    node = node -> left;
                }
            }
        }
        return preorder;
    }
};