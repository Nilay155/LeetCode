typedef long long ll;
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        ll ans = 0;

        while(j < n) {
            
            ans += (j - i + 1);
            if(j+1 < n && nums[j] == nums[j+1]) {
                i = j + 1;
            }
            j += 1;
        }
        return ans;
    }
};