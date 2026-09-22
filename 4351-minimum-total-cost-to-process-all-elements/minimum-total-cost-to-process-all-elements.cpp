using ll = long long;
class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        
        const ll MOD = 1e9 + 7;
const ll INV2 = 500000004;

ll currResources = k, count = 0, totalCost = 0;

for(int i = 0; i < n; i++) {

    if(currResources >= nums[i]) {
        currResources -= nums[i];
    }
    else {

        ll need = nums[i] - currResources;

        ll q = need / k;
        ll r = (need % k != 0) ? 1 : 0;

        ll totalOps = q + r;

        currResources += totalOps * k;
        currResources -= nums[i];

        ll N = (totalOps + count) % MOD;
        ll M = count % MOD;

        ll sumN = N * ((N + 1) % MOD) % MOD;
        sumN = sumN * INV2 % MOD;

        ll sumM = M * ((M + 1) % MOD) % MOD;
        sumM = sumM * INV2 % MOD;

        ll cost = (sumN - sumM + MOD) % MOD;

        totalCost = (totalCost + cost) % MOD;

        count += totalOps;
    }
}
        return (int) totalCost;
    }
};