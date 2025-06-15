class Solution {
private:
    int maxi = INT_MIN, mini = INT_MAX;
    void solve(string &s,int n) {

        for(int x = 0 ; x <= 9 ; x++) {
            for(int y = 0 ; y <= 9 ; y++) {
                int res = 0;
                for(int k = 0 ; k < n ; k++) {
                    if(k == 0 && s[k]-'0' == x && y == 0) break;

                    if(s[k]-'0' == x) {
                        res = res * 10 + y;
                    } else {
                        res = res * 10 + s[k]-'0';
                    }
                }
                if(res == 0) continue;
                maxi = max(maxi,res);
                mini = min(mini,res);
            }
        }
    }
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.length();
        solve(s,n);
        return maxi-mini;
    }
};