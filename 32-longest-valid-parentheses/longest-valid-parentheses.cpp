class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.length();

        vector<pair<int,int>> pairs;
        stack<int> st;
        for(int i = 0 ; i < n ; i++) {
            if(str[i] == ')' && !st.empty()) {
                pairs.push_back({st.top(),i});
                st.pop();
            } else if(str[i] == '(') {
                st.push(i);
            }
        }
        sort(pairs.begin(),pairs.end());
        if(pairs.empty())
            return 0;

        vector<pair<int,int>> result;
        int s = pairs[0].first, e = pairs[0].second;
        for(int i = 1 ; i < pairs.size() ; i++) {
            int ns = pairs[i].first, ne = pairs[i].second;
            if(ns <= e + 1) {
                e = max(e,ne);
            } else {
                result.push_back({s,e});
                s = ns,e = ne;
            }
        }
        result.push_back({s,e});

        int ans = 0;
        for(int i = 0 ; i < result.size() ; i++) {
            ans = max(ans,result[i].second - result[i].first + 1);
        }
        return ans;
    }
};