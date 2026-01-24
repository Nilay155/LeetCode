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
class FindElements {
public:
    TreeNode* root = nullptr;
    unordered_map<int,bool> vis;
    FindElements(TreeNode* root) {
        this -> root = root;
        root -> val = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front(); q.pop();
            vis[node -> val] = true;
            if(node -> left) {
                node -> left -> val = 2 * node -> val + 1;
                q.push(node -> left);
            }
            if(node -> right) {
                node -> right -> val = 2 * node -> val + 2;
                q.push(node -> right);
            }
        }

    }
    
    bool find(int target) {
        if(vis.count(target)) return true;
        else return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */