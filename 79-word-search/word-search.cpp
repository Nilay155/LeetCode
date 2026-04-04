class Solution {
private:
    bool findWord(vector<vector<char>> &board,int i,int j,string &word,int k) {

        if(k >= word.size()) return true;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        bool ans = false;

        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size() &&
               word[k] == board[ni][nj]) {
                board[ni][nj] = '.';
                ans = ans | findWord(board,ni,nj,word,k + 1);
                board[ni][nj] = word[k];

            }
        }
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size(), m = board[0].size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {

                if(word[0] == board[i][j]) {
                    char ch = board[i][j];
                    board[i][j] = '.';
                    bool ans = findWord(board,i,j,word,1);
                    board[i][j] = ch;
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};