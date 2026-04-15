class Solution {
private:
    vector<vector<bool>> boxes,columns,rows;
    bool check(vector<vector<char>> &board) {

        for(int r = 0 ; r < 9 ; r++) {
            for(int c = 0 ; c < 9 ; c++) {
                if(board[r][c] == '.')
                    return false;
            }
        }
        return true;
    }
    int getBoxNumber(int r,int c) {
        return 3 * (r / 3) + c / 3;
    }
    bool solve(vector<vector<char>> &board) {
        if(check(board))
            return true;
        
        for(int r = 0 ; r < 9 ; r++) {
            for(int c = 0 ; c < 9 ; c++) {
                if(board[r][c] != '.') continue;

                // board[r][c] == '.'
                for(char ch = '1' ; ch <= '9' ; ch++) {
                    if(!columns[c][ch - '0'] && !rows[r][ch -'0'] 
                    && !boxes[getBoxNumber(r,c)][ch - '0']) {

                        board[r][c] = ch;
                        columns[c][ch - '0'] = true;
                        rows[r][ch - '0'] = true;
                        boxes[getBoxNumber(r,c)][ch - '0'] = true;

                        if(solve(board))
                            return true;

                        columns[c][ch - '0'] = false;
                        rows[r][ch - '0'] = false;
                        boxes[getBoxNumber(r,c)][ch - '0'] = false;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        boxes = vector<vector<bool>> (10,vector<bool>(10,false));
        columns = vector<vector<bool>> (10,vector<bool>(10,false));
        rows = vector<vector<bool>> (10,vector<bool>(10,false));
        for(int r = 0 ; r < 9 ; r++) {
            for(int c = 0 ; c < 9 ; c++) {
                if(board[r][c] != '.') {
                    columns[c][board[r][c] - '0'] = true;
                    rows[r][board[r][c] - '0'] = true;
                    boxes[getBoxNumber(r,c)][board[r][c] - '0'] = true;
                    // cout << board[r][c] - '0' << "\n";
                }
            }
        }
        solve(board);
        return ;
    }
};