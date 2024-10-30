class Solution {
public:
    int dp[1002][1002][2][2];
    int solve(vector<int> &nums, int i, int prev, int flag, int check,int &n) {
        if (i >= n) {
            if(check == 1) return 0;
            else return -1e9;
        }

        if (dp[i][prev][flag][check] != -1) return dp[i][prev][flag][check];

        int op1 = -1e9, op2 = -1e9, op3 = -1e9, op5 = -1e9, op6 = -1e9;

        if (prev == 0) {  // Start of a new sequence
            op1 = solve(nums, i + 1, i, 0,check, n) + 1;
        } else {
            if ((nums[prev] < nums[i]) && flag == 0) {  // Increasing phase
                op2 = solve(nums, i + 1, i, 0, check,n) + 1;
                op3 = solve(nums, i + 1, i, 1, check,n) + 1; // Switch to decreasing
            }
            if ((nums[prev] > nums[i]) && (flag == 1)) {  // Decreasing phase
                op5 = solve(nums, i + 1, i, 1,1, n) + 1;
            }
        }

        // Option to skip current element
        op6 = solve(nums, i + 1, prev, flag,check, n);

        // Store the maximum length of the mountain subsequence achievable
        return dp[i][prev][flag][check] = max({op1, op2, op3, op5, op6});
    }

    int minimumMountainRemovals(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        nums.insert(nums.begin(), 0);  // Insert dummy value for easier indexing
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int longestMountainLength = solve(nums, 1, 0, 0, 0,n);
        // cout << longestMountainLength << endl;
        return n - longestMountainLength - 1;  // -1 for the dummy element
    }
};
