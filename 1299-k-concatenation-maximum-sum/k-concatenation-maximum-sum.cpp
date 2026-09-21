class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long ans = 0;

        long long currSum = 0, pSum = 0, pMax = 0, sSum = 0, sMax = 0;
        for(int i = 0 ; i < n ; i++) {
            currSum += arr[i];
            pSum += arr[i], sSum += arr[n - i - 1];

            pMax = max(pSum,pMax);
            sMax = max(sMax,sSum);

            ans = max(ans,(long long) currSum);
            if(currSum < 0)
                currSum = 0;
        }
    
        long long kSum = pSum, kPrevSum = 0;
        for(int i = 2; i <= k; i++) {

            // k - 1, p
            ans = max(ans, (long long) pMax + kSum);

            // s, k - 1
            ans = max(ans, (long long) sMax + kSum);

            // s, k - 2, p
            ans = max(ans, (long long) sMax + kPrevSum + pMax);

            // t * k
            kPrevSum = kSum;
            kSum = kSum + pSum;

            ans = max(ans, (long long) kSum);
            ans %= MOD;
        }
        return ans;
    }
};