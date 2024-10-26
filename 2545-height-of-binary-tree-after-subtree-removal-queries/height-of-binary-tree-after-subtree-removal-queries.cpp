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
    vector<int> nums;
    int height(TreeNode* root,vector<int> &leftArr,vector<int> &rightArr,vector<vector<int>> &parent,int p,int flag) {
        
        if(root == NULL) return -1;

        nums[root -> val] = p;
        parent[root->val][flag] = p;

        int left = 0;
        int right = 0;
        if(root -> left) left = 1 + height(root->left,leftArr,rightArr,parent,root->val,1);
        if(root -> right) right = 1 + height(root->right,leftArr,rightArr,parent,root->val,2);

        leftArr[root -> val] = left;
        rightArr[root -> val] = right;

        return max(left,right);
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = 0;
        if(root -> left) ans = ans + 1 + countNodes(root -> left);
        if(root -> right) ans = ans + 1 + countNodes(root -> right);
        return ans;
    }
    void solve(TreeNode* root,vector<int> &q,vector<int> &ans) {
        int n = countNodes(root);

        vector<vector<int>> parent(n+2,vector<int>(3,0));
        vector<int> left(n+2);
        vector<int> right(n+2);
        nums = vector<int> (n+2);

        height(root,left,right,parent,0,0);

        for(int i = 0 ; i < q.size() ; i++) {
            int node = q[i]; // deleted node
            int par = nums[node];
            
            int check = 0;
            if(parent[node][1]) check = 1;
            else check = 2;
            
            int temp = par;
            int x = (check == 1) ? 0 : left[temp];
            int y = (check == 1) ? right[temp] : 0;
            int maxi = max(x,y);

            while(nums[temp] != 0) {
                int flag = 0;
                if(parent[temp][1]) flag = 1;
                else flag = 2;

                if(flag == 1) {
                    y = right[nums[temp]];
                    maxi = max(maxi + 1,y);
                } else {
                    x = left[nums[temp]];
                    maxi = max(maxi+1,x);
                }
                temp = nums[temp];
            }
            ans.push_back(maxi);
        }
        return ;

    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        solve(root,queries,ans);
        return ans;
    }
};