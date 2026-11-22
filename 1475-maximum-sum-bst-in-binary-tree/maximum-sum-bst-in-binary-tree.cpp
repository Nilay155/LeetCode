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
    int ans = 0;
    tuple<int,int,int> f(TreeNode* root) {
        if(root == nullptr)
            return {0,INT_MAX,INT_MIN};
        
        auto [leftSubtree,lb1,ub1] = f(root -> left);
        auto [rightSubtree,lb2,ub2] = f(root -> right);
        if(leftSubtree == 1e9 || rightSubtree == 1e9)
            return {1e9,1e9,1e9};

        int currNode = root -> val;
        bool left = (root -> left ? (lb1 < currNode && ub1 < currNode) : true);

        bool right = (root -> right ? (lb2 > currNode && ub2 > currNode) : true);

        if(left && right) {
            int currSubtree = currNode + leftSubtree + rightSubtree;
            ans = max(ans,currSubtree);
            return {currSubtree,min(currNode,lb1),max(currNode,ub2)};
        } else {
            return {1e9,1e9,1e9};
        }
        return {1e9,1e9,1e9};
    }
public:
    int maxSumBST(TreeNode* root) {
        f(root);
        return ans;
    }
};