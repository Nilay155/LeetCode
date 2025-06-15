class Solution {
private:
    bool palindrome(string str) {
        int s = 0, e = str.length()-1;

        while(s <= e) {
            if(str[s] != str[e]) return false;
            s++;
            e--;
        }
        return true;
    }
private:
    void solve(vector<vector<string>> &ans,vector<string> &str,string &s,int i,int n) {
        if(i >= n) {
            ans.push_back(str);
            return;
        }

        for(int j = i ; j < n ; j++) {
            string temp = s.substr(i,j-i+1);
            if(palindrome(temp)) {
                str.push_back(temp);
                solve(ans,str,s,j+1,n);
                str.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> str;
        int n = s.length();
        solve(ans,str,s,0,n);
        return ans;
    }
};