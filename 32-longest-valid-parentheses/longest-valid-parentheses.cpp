class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<pair<char,int>> st;
        vector<int> dp(n);

        for(int i = 0 ; i < n ; i++) {

            if(s[i] == '(') {
                st.push({s[i],i});
            } else {
                if(!st.empty()) {
                    st.pop();
                } else {
                    dp[i] = -1;
                }
            }
        }
        while(!st.empty()) {
            dp[st.top().second] = -1;
            st.pop();
        }
        vector<int> temp;
        for(int i = 0 ; i < n ; i++) {
            if(dp[i] == -1) temp.push_back(i);
        }

        int ans = 0;
        int m = temp.size();
        
        if(n == 0) return ans;
        if(m == 0) return n;

        for(int i = 0 ; i < m-1 ; i++) {
            ans = max(ans,temp[i+1]-temp[i]-1);
        }
        ans = max(ans,temp[0]);
        ans = max(ans,n-temp[m-1]-1);
        return ans;
    }
};