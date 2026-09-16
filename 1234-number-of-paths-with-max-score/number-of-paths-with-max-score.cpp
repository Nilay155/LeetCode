class Solution {
private:
    static const int MOD = 1000000007;
    vector<vector<pair<int, long long>>> dp;

    pair<int, long long> maxSum(vector<string>& board, int i, int j) {
        if (i == 0 && j == 0) return {0, 1};
        if (i < 0 || j < 0) return {-1000000000, 0};

        if (dp[i][j].first != -1)
            return dp[i][j];

        int leftVal = -1e9, upVal = -1e9, upLeftVal = -1e9;
        long long leftCnt = 0, upCnt = 0, upLeftCnt = 0;

        if (j - 1 >= 0 && board[i][j - 1] != 'X') {
            auto prev = maxSum(board, i, j - 1);
            if (prev.first > -1e8) {
                int add = isdigit(board[i][j - 1]) ? (board[i][j - 1] - '0') : 0;
                leftVal = add + prev.first;
                leftCnt = prev.second;
            }
        }

        if (i - 1 >= 0 && board[i - 1][j] != 'X') {
            auto prev = maxSum(board, i - 1, j);
            if (prev.first > -1e8) {
                int add = isdigit(board[i - 1][j]) ? (board[i - 1][j] - '0') : 0;
                upVal = add + prev.first;
                upCnt = prev.second;
            }
        }

        if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] != 'X') {
            auto prev = maxSum(board, i - 1, j - 1);
            if (prev.first > -1e8) {
                int add = isdigit(board[i - 1][j - 1]) ? (board[i - 1][j - 1] - '0') : 0;
                upLeftVal = add + prev.first;
                upLeftCnt = prev.second;
            }
        }

        int best = max({leftVal, upVal, upLeftVal});
        long long ways = 0;
        if (leftVal == best) ways = (ways + leftCnt) % MOD;
        if (upVal == best) ways = (ways + upCnt) % MOD;
        if (upLeftVal == best) ways = (ways + upLeftCnt) % MOD;

        return dp[i][j] = {best, ways};
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();
        dp.assign(n, vector<pair<int, long long>>(m, {-1, 0}));
        auto [target, paths] = maxSum(board, n - 1, m - 1);
        if (target < 0) return {0, 0};
        return {target, (int)(paths % MOD)};
    }
};