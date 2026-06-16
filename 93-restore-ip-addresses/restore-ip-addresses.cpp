class Solution {
private:
    bool f(string &s,int i,vector<string> &ans,string str,int count) {
        int n = s.length();
        if(i >= n && count == 0) {
            str.pop_back();
            ans.push_back(str);
            return true;
        }
        if(i >= n || count <= 0)
            return false;
        
        bool res = false;
        string temp;
        for(int j = i ; j < min(j + 3,n) ; j++) {
            temp += s[j];   
            if(j > i && temp[0] != '0' && stoll(temp) <= 255 && count)
                res = res | f(s,j + 1,ans,str + temp + ".",count - 1);
            else if(j == i && count)
                res = res | f(s,j + 1,ans,str + temp + ".",count - 1);
        }
        return res;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();

        if(n > 12 || n < 4)
            return {};

        for(int i = 0 ; i < n ; i++) {
            if(!isdigit(s[i]))
                return {};
        }
        vector<string> ans;
        bool flag = f(s,0,ans,"",4);
        
        if(!flag)
            return {};
        return ans;
    }   
};