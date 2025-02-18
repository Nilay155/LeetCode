class Solution {
private:
    bool solve(string &ans,string &patt,int &n,int i,vector<bool> &count) {

        if(i >= n) return true;
        for(char ch = '1' ; ch <= '9' ; ch++) {
            if(count[ch-'0']) continue;
            if(patt[i] == 'I') {
                if(ans.back() < ch) {
                    ans.push_back(ch);
                    count[ch-'0'] = true;
                    if(solve(ans,patt,n,i+1,count)) return true;
                    ans.pop_back();
                    count[ch-'0'] = false;
                }
            } else {
                if(ans.back() > ch) {
                    ans.push_back(ch);
                    count[ch-'0'] = true;
                    if(solve(ans,patt,n,i+1,count)) return true;
                    ans.pop_back();
                    count[ch-'0'] = false;
                }
            }
        } 
        return false;
    }
public:
    string smallestNumber(string pattern) {
        string ans;
        int n = pattern.size();
        vector<bool> count(10,false);
        if(pattern[0] == 'I')  {
            ans += "1";
            count[1] = true;
        }
        else {
            int cnt = 0;
            for(int i = 0 ; i < n ; i++) {
                if(pattern[i] == 'D') cnt++;
                else break;
            }
            ans += to_string(cnt+1);
            count[cnt+1] = true;
        }
        solve(ans,pattern,n,0,count);
        return ans;
    }
};