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
    void dfs(TreeNode* root,int verticalLevel,
    int horizontalLevel,map<int,map<int,vector<int>>> &verticalOrder) {

        if(root == nullptr) return ;

        verticalOrder[verticalLevel][horizontalLevel].push_back(root -> val);

        // left-side => -1
        dfs(root -> left,verticalLevel-1,horizontalLevel+1,verticalOrder);
        // right-side => +1
        dfs(root -> right,verticalLevel+1,horizontalLevel+1,verticalOrder);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> verticalOrder;
        dfs(root,0,0,verticalOrder);

        vector<vector<int>> ans;
        for(auto [verticalLevel,map] : verticalOrder) {
            vector<int> temp;
            for(auto [horizontalLevel,items] : map) {
                sort(items.begin(),items.end());
                for(auto item : items) temp.push_back(item);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};