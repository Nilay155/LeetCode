class Solution {
private:
    void solve(vector<string> &ans,string s,int i,int target,long long res,char opr,string temp,int prev) {
        if(i >= s.length() && res == target) {
            ans.push_back(temp);
            return;
        }

        if(i >= s.length()) return ;

        long long num = 0;
        for(int j = i ; j < s.length() ; j++) {
            if(j > i && s[i] == '0') break;
            
            num = num*10 + (s[j]-'0');

            if(prev == -1 && i == 0) {
                solve(ans,s,j+1,target,res + num,opr,temp + to_string(num),num);
            } else {
                            // multiplication
                if(opr == '+') {
                    solve(ans,s,j+1,target,res - prev + prev*num,'+',temp + "*" + to_string(num),num*prev);
                } else if(opr == '-'){
                    solve(ans,s,j+1,target,res + prev - prev*num,'-',temp + "*" + to_string(num),num*prev);
                } else {
                    solve(ans,s,j+1,target,res*num,'*',temp + "*" + to_string(num),num);
                }
                // addition
                solve(ans,s,j+1,target,res + num,'+',temp + "+" + to_string(num),num);
                // subtraction
                solve(ans,s,j+1,target,res - num,'-',temp + "-" + to_string(num),num);
                }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(ans,num,0,target,0,' ',"",-1);
        return ans;
    }
};