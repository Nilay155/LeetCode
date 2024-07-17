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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        if(root == NULL) return {};

        map<int,vector<int>> mpp;
        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* parent = p.first;
            int level = p.second;
            mpp[level].push_back(parent -> val);

            if(parent -> left) {
                q.push({parent -> left,level + 1});
            }
            if(parent -> right) {
                q.push({parent -> right,level + 1});
            }
        }

        vector<vector<int>> ans;
        for(auto& it : mpp) {
            ans.push_back(it.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};