class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> remainders;
        remainders[0] = 1;
        int sum = 0, ans = 0;

        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
            int r = ((sum % k) + k) % k; // for negative results 

            if(remainders.find(r) != remainders.end()) {
                ans += remainders[r];
            }
            remainders[r] += 1;
        }
        return ans;
    }
};