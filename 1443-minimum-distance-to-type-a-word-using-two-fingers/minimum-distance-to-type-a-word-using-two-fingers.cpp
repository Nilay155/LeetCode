class Solution {
public:
    int dp[302][27][27];
    
    int solve(vector<pair<int,int>> &arr, string &s, int i, int f1, int f2, int &n) {
        if (i > n) return 0;
        if (dp[i][f1][f2] != -1) return dp[i][f1][f2];

        // Finger-1
        int finger1 = 0;
        if (f1 == 0) {
            finger1 = solve(arr, s, i + 1,(s[i-1]-'A')+1 , f2, n);
        } else {
            int x = f1;
            int y = s[i-1] - 'A' + 1;
            finger1 = abs(arr[x].first - arr[y].first) + abs(arr[x].second - arr[y].second) + solve(arr, s, i + 1, (s[i-1]-'A')+1, f2, n);
        }

        // Finger-2
        int finger2 = 0;
        if (f2 == 0) {
            finger2 = solve(arr, s, i + 1, f1, (s[i-1]-'A')+1, n);
        } else {
            int x = f2;
            int y = s[i-1] - 'A' + 1;
            finger2 = abs(arr[x].first - arr[y].first) + abs(arr[x].second - arr[y].second) + solve(arr, s, i + 1, f1, (s[i-1]-'A')+1, n);
        }

        return dp[i][f1][f2] = min(finger1, finger2);
    }

    int minimumDistance(string word) {
        vector<pair<int,int>> arr(27);
        int k = 1;
        for (int i = 0; i <= 3; i++) {
            for (int j = 0; j <= 5; j++) {
                arr[k++] = {i, j}; 
            }
        }
        arr[k++] = {4, 0};
        arr[k] = {4, 1};

        memset(dp, -1, sizeof(dp));
        int n = word.length();
        return solve(arr, word, 1,0,0, n);
    }
};
