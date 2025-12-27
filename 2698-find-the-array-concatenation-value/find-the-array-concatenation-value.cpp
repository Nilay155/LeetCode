typedef long long ll;
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;

        int i = 0, j = n-1;
        while(i < j) {
            string s = to_string(nums[i]) + to_string(nums[j]);
            ll val = stoll(s);
            ans += val;
            i += 1, j -= 1;
        }
        if(i == j)
            ans += nums[i];
        return ans;
    }
};