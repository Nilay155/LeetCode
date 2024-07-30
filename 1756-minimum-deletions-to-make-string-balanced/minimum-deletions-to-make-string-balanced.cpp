class Solution {
public:
    int minimumDeletions(string s) {
        // we need the string in the form of (aaaa..bbbb.. or aaaa.. or bbbb..) 
        // but not in the form (aa..bb..aa.. or bb..aa..bb..)

        int n = s.length();
        stack<char> st;
        int res = 0;

        for(int i = 0 ; i < n ; i++) {
            if(i == 0) {
                st.push(s[i]);
            } else {
                if(!st.empty() && st.top() == 'b' && s[i] == 'a') {
                    st.pop();
                    res += 1;
                } else {
                    st.push(s[i]);
                }
            }
        }
        return res;
    }
};