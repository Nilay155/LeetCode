class Solution {
private:
    vector<string> ans;
    string str;

    void f(int open,int close) {
        if(open == 0 && close == 0) {
            ans.push_back(str);
            return ;
        }
        if(open) {
            str.push_back('(');
            f(open - 1, close);
            str.pop_back();
        } 
        if(open < close) {
            str.push_back(')');
            f(open,close - 1);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        f(n,n);
        return ans;
    }
};