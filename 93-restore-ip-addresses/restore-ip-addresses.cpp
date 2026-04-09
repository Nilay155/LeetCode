class Solution {
private:
    vector<string> ans;
    void createIpAddresses(string &s,int i,int count,string res) {
        if(i >= s.length() && count == 0) {
            ans.push_back(res.substr(0,res.length() - 1));
            return ;
        }
        if(count <= 0) return ;
        string str;
        for(int j = i ; j < s.length() ; j++) {
            if((j > i && s[i] == '0') || (j - i + 1 >= 4)
                || stoi(s.substr(i,j - i + 1)) >= 256) break;

            str += s[j];
            createIpAddresses(s,j + 1,count - 1,res + str + '.');     
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        if(n <= 3 || n >= 13) return {};
        ans.clear();
        createIpAddresses(s,0,4,"");
        return ans;
    }
};