class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        stack<char> st;

        int count = 0;

        for(int i = 0 ; i < n ; i++) {

            if(s[i] == '[') st.push(s[i]);
            else {
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else count++;
            }
        }

        if(count&1) return count/2 + 1;
        else return count/2;
    }
};