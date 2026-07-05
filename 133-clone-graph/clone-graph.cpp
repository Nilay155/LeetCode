/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int,Node*> vis;
    Node* clone(Node* node) {
        int value = node -> val;
        vector<Node*> nbrs = node -> neighbors;

        Node* newNode = new Node(value,nbrs);
        vis[value] = newNode;

        for(int i = 0 ; i < (int) nbrs.size() ; i++) {
            if(vis.find(nbrs[i] -> val) == vis.end()) {
                newNode -> neighbors[i] = clone(nbrs[i]);
            } else {
                newNode -> neighbors[i] = vis[nbrs[i] -> val];
            }
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        return clone(node);
    }
};