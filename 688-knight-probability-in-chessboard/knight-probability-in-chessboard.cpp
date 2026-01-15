class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<int>> moves = {
            {-1,2},{1,2},{-1,-2},{1,-2},{2,1},{2,-1},{-2,1},{-2,-1}
        };

        vector<vector<double>> board(n,vector<double>(n,0.0));
        board[row][column] = 1.00;

        for(int m = 1 ; m <= k ; m++) {
            vector<vector<double>> nextBoard(n,vector<double>(n,0.0));
            for(int i = 0 ; i < n ; i++) {
                for(int j = 0 ; j < n ; j++) {
                    
                    for(int k = 0 ; k < 8 ; k++) {
                        int x = i + moves[k][0], y = j + moves[k][1];

                        if(x >= 0 && x < n && y >= 0 && y < n) {
                            nextBoard[x][y] += (0.125 * board[i][j]);
                        }
                    }
                }
            }
            // for(int i = 0 ; i < n ; i++) {
            //     for(int j = 0 ; j < n ; j++) {
            //         cout << nextBoard[i][j] << "  ";
            //     }    cout << "\n";
            // }
            board = nextBoard;
        }
        double ans = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                ans += board[i][j];
            }
        }
        return ans;
    }
};