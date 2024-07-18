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
int countPairs(TreeNode* root, int distance) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int res = 0;
        std::function<vector<int>(TreeNode*)> helper = [&](TreeNode* root)->vector<int>{
            if (!root) return {};
            if (!root->left && !root->right) return {1};

            vector<int> l = helper(root->left);
            vector<int> r = helper(root->right);

            for (int x : l){
                for (int y : r){
                    if (x + y <= distance) ++res;
                }
            }
            vector<int> curr;
            for (int x : l){
                if (x < distance) curr.push_back(x + 1);
            }
            for (int y : r){
                if (y < distance) curr.push_back(y + 1);
            }
            return curr;
        };

        helper(root);
        return res;
    }
};