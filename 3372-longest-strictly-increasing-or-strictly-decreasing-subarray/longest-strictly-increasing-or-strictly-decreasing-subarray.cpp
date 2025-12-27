class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // O(n)
        int n = nums.size();
        
        int c = 0, s = 0, ans = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            if(i == n-1) {
                if(c == 0) ans = max(ans,1);
                else ans = max(ans,i-s+1);
                continue;
            }
            if(i+1 < n && nums[i] == nums[i+1]) {
                ans = max(ans,i-s+1);
                c = 0, s = i+1;
                continue;
            }
            if(nums[i] > nums[i+1]) {
                // valley
                if(c == 0) {
                    c = 1;
                    s = i;
                } else if(c == 2) {
                    ans = max(ans,i-s+1);
                    c = 1;
                    s = i;
                }
            } else {
                // peak
                if(c == 0) {
                    c = 2;
                    s = i;
                } else if(c == 1) {
                    ans = max(ans,i-s+1);
                    c = 2;
                    s = i;
                }
            }
        }
        return ans;
    }
};