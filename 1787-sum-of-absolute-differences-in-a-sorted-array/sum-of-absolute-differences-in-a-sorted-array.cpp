class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n),suffix(n);
        prefix[0] = nums[0], suffix[n-1] = nums[n-1];
        for(int i = 1 ; i < n ; i++) {
            prefix[i] = nums[i] + prefix[i-1];
            suffix[n-i-1] = nums[n-i-1] + suffix[n-i];
        }

        vector<int> result(n,0);
        for(int i = 0 ; i < n ; i++) {
            int p = (i * nums[i]) - ((i-1 >= 0) ? prefix[i-1] : 0);
            int s = ((i+1 < n) ? suffix[i+1] : 0) - ((n-i-1) * nums[i]);
            result[i] = p + s;
        }
        return result;
    }
};