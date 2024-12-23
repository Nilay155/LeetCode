#define pi pair<int,int>
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
    int countSwaps(unordered_map<int,vector<int>> &mpp,int level) {
        int swaps = 0;
        
        for(int i = 0 ; i < level ; i++) {
            map<int,int> map;
            for(int j = 0 ; j < mpp[i].size() ; j++) {
                map[mpp[i][j]] = j;
            }
            int k = 0;
            for(auto& it : map) {
                // cout << it.first << endl;
                if(mpp[i][k] != it.first) {
                    swaps++;
                    
                    int temp = mpp[i][k];
                    mpp[i][k] = mpp[i][it.second];
                    mpp[i][it.second] = temp;

                    map[mpp[i][it.second]] = it.second;
                    // cout << mpp[i][k] << " : " << mpp[i][it.second] <<  endl;
                }
                k++;
            }
            // cout << swaps << endl;
        }
        return swaps;
    }
    int bfs(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 0;
        unordered_map<int,vector<int>> mpp;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            if(node == NULL) {
                level++;
                if(!q.empty()) q.push(NULL);
                continue;
            }
            mpp[level].push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return countSwaps(mpp,level);
    }
    int minimumOperations(TreeNode* root) {
        return bfs(root);
    }
};