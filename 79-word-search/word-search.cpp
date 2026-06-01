class Solution {
private:
    bool dfs(vector<vector<char>> &board,int i,int j,string &word,int k) {
        if(k >= word.length())
            return true;
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};

        for(int u = 0 ; u < 4 ; u++) {
            int ni = dx[u] + i, nj = dy[u] + j;
            if(ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size() && board[ni][nj] != '.' && board[ni][nj] == word[k]) {
                
                char ch = board[ni][nj];
                board[ni][nj] = '.';
                if(dfs(board,ni,nj,word,k + 1)) 
                    return true;
                board[ni][nj] = ch;
                
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        bool ans = false;
        int n = board.size(), m = board[0].size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {

                if(board[i][j] == word[0]) {
                    board[i][j] = '.';
                    ans = ans | dfs(board,i,j,word,1);
                    board[i][j] = word[0];
                    if(ans) return ans;
                }
            }
        }
        return ans;
    }
};