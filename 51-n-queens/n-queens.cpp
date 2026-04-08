class Solution {
private:
    vector<bool> columns,leftDiagonal,rightDiagonal;
private:
    bool checkAttacks(int i,int j,int n) {
        if(!columns[j] && !rightDiagonal[i + j] && !leftDiagonal[n + i - j - 1])
            return true;
        return false;
    }
    void placeQueens(int i,int n,vector<string> &res,vector<vector<string>> &ans) {
        if(i == n) {
            ans.push_back(res);
            return ;
        }

        for(int j = 0 ; j < n ; j++) {

            if(checkAttacks(i,j,n)) {
                res[i][j] = 'Q';
                columns[j] = true;
                rightDiagonal[i + j] = true;
                leftDiagonal[n + i - j - 1] = true;

                placeQueens(i + 1,n,res,ans);

                res[i][j] = '.';
                columns[j] = false;
                rightDiagonal[i + j] = false;
                leftDiagonal[n + i - j - 1] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        string str;
        str.append(n,'.');
        vector<string> res(n,str);

        columns = vector<bool> (n,false);
        leftDiagonal = vector<bool> (2*n - 1,false);
        rightDiagonal = vector<bool> (2*n - 1,false);

        placeQueens(0,n,res,ans);
        return ans;
    }
};