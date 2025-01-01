class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> zeroes(n),ones(n);

        int zr = 0, on = 0;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '0') zr++;
            zeroes[i] = zr;
        }
        for(int i = n-1 ; i >= 0 ; i--) {
            if(s[i] == '1') on++;
            ones[i] = on;
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            int temp = zeroes[i];
            if(i+1 < n) temp += ones[i+1];
            else temp = INT_MIN;
            ans = max(ans,temp);
        }
        return ans;
    }
};