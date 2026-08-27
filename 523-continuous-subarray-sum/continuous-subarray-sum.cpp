class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> remainders;
        remainders[0] = -1;

        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
            int r = sum % k;

            if(remainders.find(r) != remainders.end()) {
                int j = remainders[r];
                if(i - j >= 2) {
                    return true;
                }
            } else {
                remainders[r] = i;
            }
        }
        return false;
    }
};