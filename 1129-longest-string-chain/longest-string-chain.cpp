class Solution {
public:
    static bool cmp(string &a,string &b) {
        return a.length() < b.length();
    }
    bool isPossible(string &s1,string &s2) {
        int n = s1.length();
        int m = s2.length();
        if(n+1 != m) return false;

        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i < n) {
            if(s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                cnt++;
                j++;
            }
            if(cnt > 1) return false;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),cmp);

        // HashTable Preparation
        // vector<vector<int>> arr(n,vector<int>(26,0));
        // for(int i = 0 ; i < n ; i++) {
        //     string str = words[i];
        //     int m = str.length();

        //     for(int j = 0 ; j < m ; j++) {
        //         arr[i][str[j]-'a']++;
        //     }
        // }
        // DP
        vector<int> dp(n,0);
        dp[n-1] = 1;

        for(int i = n-2 ; i >= 0 ; i--) {
            string s1 = words[i];
            for(int j = i+1 ; j < n ; j++) {
                string s2 = words[j];

                if(isPossible(s1,s2)) {
                    dp[i] = max(dp[i],1 + dp[j]);
                } else {
                    dp[i] = max(1,dp[i]);
                }
            } 
        }

        int res = 1;

        for(int i = 0 ; i < n ; i++) {
            res = max(res,dp[i]);
        }
        return res;
    }
};