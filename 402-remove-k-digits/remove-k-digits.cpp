class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();

        stack<int>st;

        for(int i = 0 ; i < n ; i++) {
            int val = num[i]-'0';

            while(!st.empty() && st.top() > val && k) {
                st.pop();
                k--;
            }

            st.push(val);
        }

        while(k-- && !st.empty()) {
            st.pop();
        }
        string res;
        while(!st.empty()) {
            res += to_string(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        int l = 0, m = res.length();
        string ans;
        while(l < m && res[l] == '0') {
            l++;
        }

        while(l < m) {
            ans.push_back(res[l]);
            l++;
        }

        if(ans.empty()) return "0";
        else return ans;
    }
};