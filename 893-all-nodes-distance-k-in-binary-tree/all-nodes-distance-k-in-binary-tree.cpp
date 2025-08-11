/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void KthDistances(vector<vector<int>> &adjMatrix,vector<bool> &vis,vector<int> &ans,int k, int src) {

        if(k <= 0) {
            ans.push_back(src);
            return ;
        }
        vis[src] = true;

        for(int i = 0 ; i < 501 ; i++) {
            if(adjMatrix[src][i] == 1 && !vis[i]) {
                KthDistances(adjMatrix,vis,ans,k-1,i);
            }
        }
    }

    void dfs(TreeNode* root,vector<vector<int>> &adjMatrix) {
        if(root == nullptr) return ;

        if(root -> left) {
            adjMatrix[root -> val][root -> left -> val] = 1;
            adjMatrix[root -> left -> val][root -> val] = 1;
            dfs(root -> left,adjMatrix);
        } 
        if(root -> right) {
            adjMatrix[root -> val][root -> right -> val] = 1;
            adjMatrix[root -> right -> val][root -> val] = 1;
            dfs(root -> right,adjMatrix);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<bool> vis(501,false);
        vector<int> ans;
        vector<vector<int>> adjMatrix(501,vector<int>(501,0));
        dfs(root,adjMatrix);
        KthDistances(adjMatrix,vis,ans,k,target -> val);
        return ans;

    }
};