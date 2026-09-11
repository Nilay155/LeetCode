class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        stack<int> st;
        vector<int> bracket(n,-1);

        for(int i = 0 ; i < n ; i++) {
            char ch = s[i];
            if(ch == '(') {
                st.push(i);
            } else {
                if(!st.empty())
                    bracket[i] = st.top(), st.pop();
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(bracket[i] != -1) {
                int prev = bracket[i];
                if(prev - 1 >= 0 && bracket[prev - 1] != -1) {
                    bracket[i] = bracket[prev - 1];
                }
            }
        }

        for(int i = 0 ; i < n ; i++) {
            if(bracket[i] != -1) {
                ans = max(ans,i - bracket[i] + 1);
            }
        }
        return ans;
    }
};