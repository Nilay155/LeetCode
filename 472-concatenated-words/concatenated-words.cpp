class Solution {
private:
    unordered_map<string,bool> wordss;
    int f(string &s,int i,int n,vector<int> &dp) {
        if(i >= n) 
            return 1;

        if(dp[i] != -1) return dp[i];

        int ans = 0;
        for(int l = 1 ; l <= (n - i) ; l++) {
            if(wordss.find(s.substr(i,l)) != wordss.end()) {
                ans += f(s,i + l,n,dp);
            }
        }
        return dp[i] = ans;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        for(string str : words)
            wordss[str] = true;

        vector<string> ans;
        for(int i = 0 ; i < n ; i++) {
            vector<int> dp(31,-1);
            if(f(words[i],0,words[i].length(),dp) > 1) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};