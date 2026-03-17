class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> prefixSum(n);
        prefixSum[0] = arr[0];
        for(int i = 1 ; i < n ; i++) prefixSum[i] = arr[i] + prefixSum[i-1];

        int maxSum = 0;
        for(int i = 0 ; i < n ; i++) {
            maxSum = max(prefixSum[i],maxSum);
        }
        k -= 1;

        long long sum = 0, maxi = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += arr[i];

            long long totalSum = prefixSum[n-1];
            long long roundSum = (long long) (k-1) * totalSum;
            long long remainingSum = maxSum;
            long long finalSum = (roundSum + remainingSum) % MOD;

            maxi = max(maxi,sum);
            if(k > 0) {
                long long restSum = prefixSum[n-1] - prefixSum[i];
                maxi = max({maxi,sum + restSum + maxSum, sum + finalSum + restSum});
            }
            maxi %= MOD;
            // Applying kadane's for the existing one
            if(sum <= 0) sum = 0;
        }
        return maxi;
    }
};