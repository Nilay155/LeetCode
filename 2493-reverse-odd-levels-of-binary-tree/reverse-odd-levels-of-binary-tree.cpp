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
    unordered_map<int,vector<int>> map;
    void dfs(TreeNode* root,int lvl) {
        if(!root) return ;

        if(lvl&1) {
            root -> val = map[lvl].back();
            map[lvl].pop_back();
        }
        dfs(root->left,lvl+1);
        dfs(root->right,lvl+1);
    }
    void vot(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 0;

        while(!q.empty()) {

            auto node = q.front();
            q.pop();
            if(node == NULL) {
                level += 1;
                if(!q.empty()) q.push(NULL); 
                continue;
            }
            if(level&1) map[level].push_back(node->val);
            if(node->left) {
                q.push(node->left);
            
            }
            if(node->right) {
                q.push(node->right);
            }

        }

        dfs(root,0);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        vot(root);
        return root;
    }
};