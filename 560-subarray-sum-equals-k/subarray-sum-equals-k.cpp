class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long,int> prefixesCount;
        prefixesCount[0] = 1;
        long long sum = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
            long long prefix = sum - k;
            if(prefixesCount.count(prefix)) {
                ans += prefixesCount[prefix];
            }
            prefixesCount[sum] += 1;
        }
        return ans;
    }
};