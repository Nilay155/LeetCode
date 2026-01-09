class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> counts;
        for(int num : nums) counts[num] += 1;

        int val = -1, maxi = 0;
        for(auto [v,c] : counts) {
            if(c > maxi) {
                maxi = c, val = v;
            }
        }

        int prefixCount = 0;
        for(int i = 0 ; i <= n-2 ; i++) {
            prefixCount += (nums[i] == val ? 1 : 0);

            int left = prefixCount, right = maxi - left;
            if(left > (i+1) / 2 && right > (n - i - 1) / 2) 
                return i;
        }
        return -1;
    }
};