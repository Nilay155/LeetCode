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
    int maxPath = 0;
    int zigZagPath(TreeNode* root,int move) {
        if(root == nullptr)
            return 0;
        
        // move = 1 -> Left, move = 2 -> right
        int left = zigZagPath(root -> left,1);
        int right = zigZagPath(root -> right,2);

        // cout << left << " : " << right << "\n";
        maxPath = max({maxPath,left,right});
    
        if(move == 1)
            return 1 + right;
        else if(move == 2)
            return 1 + left;
        else
            return max(left,right);

    }
public:
    int longestZigZag(TreeNode* root) {
        zigZagPath(root,0);
        return maxPath;
    }
};