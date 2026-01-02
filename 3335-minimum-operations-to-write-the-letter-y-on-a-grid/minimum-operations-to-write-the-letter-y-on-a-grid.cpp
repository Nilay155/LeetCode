class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int z = 0 , o = 0 , t = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 0) z++;
                else if(grid[i][j] == 1) o++;
                else t++;
            }
        }
        int yz = 0, yo = 0, yt = 0;
        int s = 0,e = 0;
        // left-diagonal
        while(s <= n/2 && e <= n/2) {
            if(grid[s][e] == 0) yz++;
            else if(grid[s][e] == 1) yo++;
            else yt++;
            s++,e++;
        }
        s--,e--;
        // right-diagonal
        int u = s-1, v = e+1;
        while(u >= 0 && v < n) {
            if(grid[u][v] == 0) yz++;
            else if(grid[u][v] == 1) yo++;
            else yt++;
            u--,v++;
        }
        // center-bottom line
        int x = s+1,y = e;
        while(x < n) {
            if(grid[x][y] == 0) yz++;
            else if(grid[x][y] == 1) yo++;
            else yt++;
            x++;
        }
        z -= yz, o -= yo, t -= yt;

        // cout << z << "  " << o << "  " << t <<"\n";
        // cout << yz << "  " << yo << "  " << yt << "\n"; 
        int ans = INT_MAX;
        // 0-1, 1-0, 0-2,2-0,1-2,2-1
        int op1 = yt + yo + z + t;
        int op2 = yz + yt + o + t;
        int op3 = yo + yt + o + z;
        int op4 = yo + yz + t + o;
        int op5 = yz + yt + o + z;
        int op6 = yz + yo + t + z;
        ans = min({ans,op1,op2,op3,op4,op5,op6});
        return ans;
    }
};