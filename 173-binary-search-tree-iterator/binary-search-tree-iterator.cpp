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
class BSTIterator {
private:
    vector<int> inOrder = {-1};
    int k = 0;
    void inorder(TreeNode* root) {
        if(root == nullptr) return ;

        inorder(root -> left);
        inOrder.push_back(root -> val);
        inorder(root -> right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        int n = inOrder.size();
        k += 1;
        if(k < n) return inOrder[k];
        else return -1;
    }
    
    bool hasNext() {
        int n = inOrder.size();
        if(k + 1 < n) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */