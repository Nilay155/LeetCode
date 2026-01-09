typedef long long ll;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;

        ll sum = 0, ans = 0, even = 1, odd = 0;

        for(int i = 0 ; i < n ; i++) {
            sum += arr[i];

            if(sum % 2 == 0) {
                ans = (ans + odd) % mod;
                even += 1;
            } else {
                ans = (ans + even) % mod;
                odd += 1;
            }
        }
        return ans;
    }
};