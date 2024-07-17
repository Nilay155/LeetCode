class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<int>> rows(9,vector<int> (9,0));
        vector<vector<int>> cols(9,vector<int> (9,0));
        vector<vector<int>> boxes(9,vector<int> (9,0));

        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                
                if(board[i][j] != '.') {

                    int digit = board[i][j]-'0';
                    int box = i / 3 * 3 + j / 3;

                    if(rows[i][digit-1]) return false;
                    else if(cols[j][digit-1]) return false;
                    else if(boxes[box][digit-1]) return false;
                    else {
                        rows[i][digit-1] = 1;
                        cols[j][digit-1] = 1;
                        boxes[box][digit-1] = 1;
                    }
                }
            }
        }
        return true;
    }
};