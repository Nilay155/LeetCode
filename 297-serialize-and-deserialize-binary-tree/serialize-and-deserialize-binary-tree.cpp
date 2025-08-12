/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    vector<string> splitOnSpaces(const string &str) {
        vector<string> result;
        stringstream ss(str);
        string word;
        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }
    string serialization(TreeNode* root) {
        string ans;
        if(root == nullptr) return ans;


        queue<TreeNode*> q;
        q.push(root);
        ans += to_string(root -> val);
        ans += " ";

        while(!q.empty()) {
            auto node = q.front(); q.pop();

            if(node -> left){
                ans += to_string(node -> left -> val);
                ans += " ";
                q.push(node -> left);
            } else {
                ans += "N";
                ans += " ";
            }

            if(node -> right) {
                ans += to_string(node -> right -> val);
                ans += " ";
                q.push(node -> right);
            } else {
                ans += "N";
                ans += " ";
            }
        }
        // cout << ans << endl;
        return ans;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serialization(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {

        if(s.empty()) return nullptr;
        vector<string> words = splitOnSpaces(s);
        
        vector<int> data;
        for(int i = 0 ; i < words.size() ; i++) {
            if(words[i][0] == 'N') {
                data.push_back(INT_MAX);
            } else {
                data.push_back(stoi(words[i]));
            }
        }

        int k = 1, n = data.size();
        TreeNode* node = new TreeNode(data[0]);

        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty() && k < n) {
            // cout << data[k] << endl;
            auto root = q.front(); q.pop();

            if(data[k] == INT_MAX) {
                root -> left = nullptr;
            } else {
                root -> left = new TreeNode(data[k]);
                q.push(root -> left);
            }
            k++;

            if(data[k] == INT_MAX) {
                root -> right = nullptr;
            } else {
                root -> right = new TreeNode(data[k]);
                q.push(root -> right);
            }
            k++;
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));