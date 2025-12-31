class Solution {
public:
    int minPartitions(string s) {
        int n = s.length();

        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            ans = max(ans,s[i]-'0');
        }
        return ans;
    }
};