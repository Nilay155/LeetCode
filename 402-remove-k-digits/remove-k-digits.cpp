class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int n = num.length();

        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && st.top() > (num[i] -'0') && k) {
                st.pop();
                k--;
            }
            st.push((num[i]-'0'));
        }
        while(k--) st.pop();

        string temp;
        while(!st.empty()) {
            temp.push_back(st.top() + '0');
            st.pop();
        }
        reverse(temp.begin(),temp.end());

        for(int i = 0 ; i < (int) temp.size() ; i++) {
            if(temp[i] != '0')
                return temp.substr(i,temp.size() - i + 1);
        }
        return "0";
    }
};