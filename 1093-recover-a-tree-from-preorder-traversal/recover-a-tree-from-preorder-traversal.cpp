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
    int node(string &traversal,int &i,int n) {
        int parent = 0;
        while(i < n && traversal[i] != '-') {
            parent = parent * 10 + (traversal[i]-'0');
            i++;
        }
        return parent;
    }
    int depth(string &traversal,int &i,int n) {
        int d = 0;
        while(i < n && !isdigit(traversal[i])) {
            d++;
            i++;
        }
        return d;
    }
    void recover(TreeNode* &root,vector<pair<int,int>> &arr,int depth,int &i) {
        // NLR

        int d = -1, node = -1;
        if(i < arr.size()) {
            d = arr[i].second;
            node = arr[i].first;
        }
        // Left Child
        if(d == depth) {
            if(!root -> left) {
                root -> left = new TreeNode(node);
                i += 1;
                recover(root->left,arr,depth+1,i);
            }
        }
        
        d = -1, node = -1;
        if(i < arr.size()) {
            d = arr[i].second;
            node = arr[i].first;
        }
        // Right Child
        if(d == depth) {
            if(!root -> right) {
                root -> right = new TreeNode(node);
                i += 1;
                recover(root->right,arr,depth+1,i);
            }
        }
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        unordered_map<int,vector<int>> left,right,map;
        vector<pair<int,int>> arr;
        int i = 0;

        int parent = 0;
        int d = 0;

        while(i < n) {
            parent = node(traversal,i,n);
            map[d].push_back(parent);
            arr.push_back({parent,d});
            d = depth(traversal,i,n);
        }
        TreeNode* root = new TreeNode(map[0][0]);
        // reverse(arr.begin(),arr.end());
        for(int i = 0 ; i < arr.size() ; i++) {
            // cout << arr[i].first << "  " << arr[i].second << endl;
        } 
        // arr.pop_back();
        int x = 1;
        recover(root,arr,1,x);
        return root;
    }
};