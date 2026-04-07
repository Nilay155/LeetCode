class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD = 1e9 + 7;
        vector<long long> subArrays;
        for(int i = 0 ; i < n ; i++) {
            long long sum = 0;
            for(int j = i ; j < n ; j++) {
                sum += nums[j];
                subArrays.push_back(sum);
            }
        }
        sort(subArrays.begin(),subArrays.end());
        int totalPairs = (n * (n + 1)) / 2;
        vector<long long> prefix(totalPairs);
        prefix[0] = subArrays[0];
        for(int i = 1 ; i < totalPairs ; i++) prefix[i] = subArrays[i] + prefix[i - 1];

        left -= 1, right -= 1;
        long long rangeSumm = prefix[right] - (left - 1 >= 0 ? prefix[left - 1] : 0);
        return rangeSumm % MOD; 
    }
};