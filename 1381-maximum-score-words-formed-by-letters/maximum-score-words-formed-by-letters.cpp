class Solution {
private:
    unordered_map<int,unordered_map<string,int>> dp;
    int maximumScore(vector<string> &words,int i,string res,vector<int> &counts,vector<int> &scores) {
        if(i >= words.size()) {
            // a Valid soln is found
            int ans = 0;
            for(int j = 0 ; j < res.length() ; j++) {
                ans += scores[res[j] - 'a'];
            }
            return ans;
        }
        if(dp.count(i) && dp[i].count(res)) return dp[i][res];

        int notPick = maximumScore(words,i+1,res,counts,scores);
        int pick = 0;

        string newStr = res + words[i];
        vector<int> newCount(26,0);
        for(int j = 0 ; j < newStr.length() ; j++) {
            newCount[newStr[j]-'a'] += 1;
        }

        bool flag = true;
        for(int j = 0 ; j < 26 ; j++) {

            if(newCount[j] > counts[j]) {
                flag = false;
                break;
            }
        }
        if(flag) pick = maximumScore(words,i+1,newStr,counts,scores);
        return dp[i][res] = max(pick,notPick);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& scores) {
        int n = words.size();

        vector<int> counts(26,0);
        for(int i = 0 ; i < (int) letters.size() ; i++) {
            counts[letters[i] - 'a'] += 1;
        }
        string res;
        return maximumScore(words,0,res,counts,scores);
    }
};