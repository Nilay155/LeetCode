class Solution {
private:
    bool check(vector<string> &str,int n,int i,int j) {

        // Top Direction
        for(int k = i-1 ; k >= 0 ; k--) {
            if(str[k][j] == 'Q') return false; 
        }
        // Top-Left Direction
        int x = i-1, y = j-1;
        while(x >= 0 && y >= 0) {
            if(str[x][y] == 'Q') return false;
            x -= 1,y -= 1;
        }
        x = i-1,y = j+1;
        while(x >= 0 && y < n) {
            if(str[x][y] == 'Q') return false;
            x -= 1, y += 1;
        }
        return true;
    }
private:
    void solve(vector<vector<string>> &ans,vector<string> &str,int n,int i) {
        if(i >= n) {
            ans.push_back(str);
            return ;
        }

        for(int j = 0 ; j < n ; j++) {

            if(check(str,n,i,j)) {
                str[i][j] = 'Q';
                solve(ans,str,n,i+1);
                str[i][j] = '.';
            } 
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s;

        int t = n;
        while(t--) {
            s.push_back('.');
        }
        vector<string> str(n,s);

        solve(ans,str,n,0);
        return ans;
    }
};