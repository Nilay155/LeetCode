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
    pair<int,int> maximumTheft(TreeNode* root) {
        if(root == nullptr) return {0,0};

        auto [lr,lnr] = maximumTheft(root -> left);
        auto [rr,rnr] = maximumTheft(root -> right);
        
        int rob = root -> val + lnr + rnr;
        int noRob = max({lr + rr,lr + rnr,rr + lnr,lnr + rnr});
        return {rob,noRob};
    }
public:
    int rob(TreeNode* root) {
        auto [k1,k2]= maximumTheft(root);
        return max(k1,k2);
    }
};