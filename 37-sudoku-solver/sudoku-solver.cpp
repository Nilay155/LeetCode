class Solution {
private:
bool check(vector<vector<char>> &board, int i, int j, char val)
{
    int row = i - i%3, column = j - j%3;
    for(int x=0; x<9; x++) if(board[x][j] == val) return false;
    for(int y=0; y<9; y++) if(board[i][y] == val) return false;
    for(int x=0; x<3; x++)
    for(int y=0; y<3; y++)
        if(board[row+x][column+y] == val) return false;
    return true;
}
private:
    bool solve(vector<vector<char>> &board,int i,int j) {
        if(i == 9) return true;
        

        for(char ch = '1' ; ch <= '9' ; ch++) {
            while(j < 9 && board[i][j] != '.') j++;
            if(j == 9) return solve(board,i+1,0);
            if(board[i][j] == '.' && check(board,i,j,ch)) {
                board[i][j] = ch;
                if(solve(board,i,j+1)) return true;
                board[i][j] = '.';
            } 
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};