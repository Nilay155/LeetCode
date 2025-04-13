class Solution {
private:
    long long int dp[17][2];
    long long count(string &s,int idx,int tight,int &limit,string &str) {

        if(idx >= s.size()-str.size()) {
            if(tight) {
                if(stoll(str) <= stoll(s.substr(s.size()-str.size(),str.size())))
                    return 1;
                else 
                    return 0;
            }
            return 1;  
        }
        if(dp[idx][tight] != -1) return dp[idx][tight];

        long long res = 0;
        for(int k = 0 ; k <= limit ; k++) {
            if(tight) {
                if(s[idx]-'0' > limit) {
                    res += count(s,idx+1,0,limit,str);
                } else {
                    // limit >= s[idx]-'0'
                    if(k == s[idx]-'0') res += count(s,idx+1,1,limit,str);
                    else if(k < s[idx]-'0')res += count(s,idx+1,0,limit,str);
                }
            } else {
                res += count(s,idx+1,0,limit,str);
            }
        }
        return dp[idx][tight] = res;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string str) {
        // Concepts of digit DP
        string s = to_string(start-1);
        string e = to_string(finish);
        long long L = 0, R = 0;

        memset(dp,-1,sizeof(dp));
        if(e.size()>= str.size())
            R = count(e,0,1,limit,str);
        memset(dp,-1,sizeof(dp));
        if(s.size() >= str.size())
            L = count(s,0,1,limit,str);
        
        return R-L;
    }
};