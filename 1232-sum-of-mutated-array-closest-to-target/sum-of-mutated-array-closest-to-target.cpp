class Solution {
public:
    int findBestValue(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int limit = nums[n - 1];
        vector<int> prefixSum(n,0);
        
        prefixSum[0] = nums[0];
        for(int i = 1 ; i < n ; i++) prefixSum[i] = nums[i] + prefixSum[i - 1];

        int ans = INT_MAX, diff = INT_MAX;
        int l = 0, r = limit;

        while(l <= r) {
            // cout << l << "   " << r << "\n";
            int mid = l + (r - l) / 2;
            int index = upper_bound(nums.begin(),nums.end(),mid) - nums.begin();

            int newSum = (index - 1 >= 0) ? prefixSum[index - 1] : 0;
            newSum += (n - index) * mid;

            if(abs(target - newSum) <= diff) {
                int temp = abs(target - newSum);
                if(temp == diff) ans = min(ans,mid);
                else ans = mid;
                diff = temp;
            }

            if(newSum >= target) r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};