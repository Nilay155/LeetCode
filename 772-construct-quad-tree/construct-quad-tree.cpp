/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    int check(vector<vector<int>> &grid,int sr,int er,int sc,int ec) {
        
        int ele = -1e9;

        for(int i = sr ; i <= er ; i++) {
            for(int j = sc ; j <= ec ; j++) {
                if(ele == -1e9) ele = grid[i][j];
                else if(ele !=  grid[i][j]) return 1e9;
            }
        }
        return ele;
    }
private:
    Node* solve(vector<vector<int>> &grid,int sr,int er,int sc,int ec) {
        int res = check(grid,sr,er,sc,ec);
        Node* node = NULL;
        if(res == 1e9) {

            // Any One Box Has Disperancy
            int sr1 = sr, er1 = (sr + er)/2, sc1 = sc, ec1 = (sc + ec)/2; // BOX-1
            int sr2 = sr, er2 = (sr + er)/2, sc2 = (sc + ec)/2 + 1, ec2 = ec; // BOX-2
            int sr3 = (sr + er)/2 + 1, er3 = er, sc3 = sc, ec3 = (sc + ec)/2; // BOX-3
            int sr4 = (sr + er)/2 + 1, er4 = er, sc4 = (sc + ec)/2 + 1, ec4 = ec; // BOX-4
            
            node = new Node(true,false);
            node -> topLeft = solve(grid,sr1,er1,sc1,ec1);
            node -> topRight = solve(grid,sr2,er2,sc2,ec2);
            node -> bottomLeft = solve(grid,sr3,er3,sc3,ec3);
            node -> bottomRight = solve(grid,sr4,er4,sc4,ec4);
        } else {
            // Leaf Node Hain Base Condition
            // cout << res << endl;
            // cout << sr << " " << er << " " << sc << " " << ec << endl;
            bool temp = res;
            node = new Node(temp,true);
        }
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        // 2^0 = 1 , 2^1 = 2 (2*2 = 4)

        int n = grid.size();
        return solve(grid,0,n-1,0,n-1);
    }
};