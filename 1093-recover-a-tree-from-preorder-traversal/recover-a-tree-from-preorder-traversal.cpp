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
    vector<int> dashCounts;
    vector<int> nodeValues;
    TreeNode* constructTree(string &str,int &i,int &j,int depth) {
        if(i >= nodeValues.size())
            return nullptr;
        
        TreeNode* node = new TreeNode(nodeValues[i]);
        
        if(j < dashCounts.size() && depth == dashCounts[j])
            node -> left = constructTree(str,++i,++j,depth + 1);
        
        if(j < dashCounts.size() && depth == dashCounts[j])
            node -> right = constructTree(str,++i,++j,depth + 1);
        
        return node;

    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        string str;
        int count = 0, n = traversal.length();

        for(int i = 0 ; i < n ; i++) {
            if(traversal[i] == '-')
                count += 1;
            else {
                if(count > 0)
                    dashCounts.push_back(count);
                count = 0;
            }
        }

        int number = 0;
        for(int i = 0 ; i < n ; i++) {

            if(isdigit(traversal[i])) {
                number = number * 10 + (traversal[i] - '0');
            } else {
                if(number > 0) 
                    nodeValues.push_back(number);
                number = 0;
            }
        } 
        if(number > 0)
            nodeValues.push_back(number);
        int k1 = 0, k2 = 0;
        return constructTree(traversal,k1,k2,1);
    }
};