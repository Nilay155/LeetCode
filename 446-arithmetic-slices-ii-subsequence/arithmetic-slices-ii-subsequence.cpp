class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,unordered_map<long long,int>> differences;
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i - 1 ; j >= 0 ; j--) {
                long long diff = (long long) nums[j] - (long long) nums[i];
                if(differences.count(j) && differences[j].count(diff)) {
                    ans += differences[j][diff];
                }
                differences[i][diff] += (1 + differences[j][diff]);
            }
        }
        return ans;
    }
};