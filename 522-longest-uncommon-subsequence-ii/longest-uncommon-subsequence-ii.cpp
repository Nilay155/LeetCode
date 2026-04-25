class Solution {
private:
    unordered_map<string,int> subsequenceCounts;
    void subsequences(string &s,string &t,int i,int &n) {
        if(i >= n) {
            subsequenceCounts[t] += 1;
            return ;
        }
        subsequences(s,t,i + 1,n);

        t.push_back(s[i]);
        subsequences(s,t,i + 1,n);
        t.pop_back();
    }
public:
    int findLUSlength(vector<string>& strs) {
        subsequenceCounts.clear();
        for(int i = 0 ; i < strs.size() ; i++) {
            string s = strs[i],t;
            int n = s.length();
            subsequences(s,t,0,n);
        }
        int maxLength = -1;
        for(auto [str,count] : subsequenceCounts) {
            if(count == 1) 
                maxLength = max(maxLength,(int) str.length());
        }
        return maxLength;
    }
};