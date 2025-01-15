class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        vector<string> res;
        vector<int> count(26);
        for(int i = 0 ; i < m ; i++) {
            vector<int> temp(26);
            for(int j = 0 ; j < words2[i].size() ; j++) {
                temp[words2[i][j]-'a']++;
            }
            for(int j = 0 ; j < 26 ; j++) {
                count[j] = max(count[j],temp[j]);
            }
        }

        vector<vector<int>> dp(n,vector<int>(26));

        for(int i = 0 ; i < n ; i++) {
            
            for(int j = 0 ; j < words1[i].size() ; j++) {
                dp[i][words1[i][j]-'a']++;
            }
        }

        for(int i = 0 ; i < n ; i++) {
            vector<int> temp(26);
            for(int j = 0 ; j < 26 ; j++) {
                if(count[j] && dp[i][j]) {
                    if(dp[i][j] > count[j])
                        temp[j] = count[j];
                    else 
                        temp[j] = dp[i][j];
                }
            }
            if(temp == count) res.push_back(words1[i]);
        }
        return res;
    }
};