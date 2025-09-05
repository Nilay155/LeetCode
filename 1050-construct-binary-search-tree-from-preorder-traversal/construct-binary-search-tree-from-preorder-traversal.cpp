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
    TreeNode* buildTree(vector<int> &preorder,int &pre,int par) {
        if(pre >= preorder.size() || preorder[pre] > par) return nullptr;

        TreeNode* node = new TreeNode(preorder[pre++]);

        node -> left = buildTree(preorder,pre,node -> val);
        node -> right = buildTree(preorder,pre,par);

        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pre = 0;
        return buildTree(preorder,pre,INT_MAX);
    }
};