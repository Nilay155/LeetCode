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
    unordered_map<int,int> inMap;
    TreeNode* binaryTree(vector<int> &inorder,vector<int> &postorder,int &post,int l,int r) {

        if(l > r) return nullptr;

        TreeNode* node = new TreeNode(postorder[post]);

        int inorderIndex = inMap[postorder[post]];

        post--;
        node -> right = binaryTree(inorder,postorder,post,inorderIndex + 1,r);
        node -> left = binaryTree(inorder,postorder,post,l,inorderIndex-1);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0 ; i < n ; i++) inMap[inorder[i]] = i;
        int post = n-1;
        return binaryTree(inorder,postorder,post,0,n-1);
    }
};