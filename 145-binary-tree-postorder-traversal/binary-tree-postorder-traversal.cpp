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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        TreeNode* node = root;

        while(node != nullptr) {

            postorder.push_back(node -> val);

            if(node -> right == nullptr) {
                node = node -> left;
            } else {
                TreeNode* predecessor = node -> right;

                while(predecessor -> left != nullptr && predecessor -> left != node) {
                    predecessor = predecessor -> left;
                }
                if(predecessor -> left == node) {
                    postorder.pop_back();
                    predecessor -> left = nullptr;
                    node = node -> left;
                } else {
                    predecessor -> left = node;
                    node = node -> right;
                }
            }
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
};