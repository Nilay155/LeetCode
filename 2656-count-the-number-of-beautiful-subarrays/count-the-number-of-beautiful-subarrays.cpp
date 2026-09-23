using ll = long long;
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> bitCount(32,0);
        unordered_map<string,ll> counts;

        ll ans = 0;

        string s;
        for(int i = 0 ; i < 32 ; i++)
            s.push_back('E');
        counts[s] += 1;

        for(int i = 0 ; i < n ; i++) {

            int k = nums[i];
            for(int j = 0 ; j < 32 ; j++) {
                if(k & (1 << j)) 
                    bitCount[j] += 1;
            }

            string s;
            for(int j = 0 ; j < 32 ; j++) {
                if(bitCount[j] & 1)
                    s.push_back('O');
                else
                    s.push_back('E');
            }

            ll prevCounts = counts[s];
            ans += prevCounts;
            counts[s] += 1;
        }
        return ans;
    }
};