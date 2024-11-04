class Solution {
public:
    string compressedString(string s) {
        int n = s.size();

        stack<pair<char,int>> st;

        for(int i = 0 ; i < n ; i++) {

            if(st.empty()) {
                st.push({s[i],1});
            } else {
                if(st.top().first == s[i]) {
                    char ch = st.top().first;
                    int count = st.top().second;
                    if(count == 9) {
                        st.push({ch,1});
                    } else {
                        st.pop();
                        st.push({ch,count+1});
                    }
                } else {
                    st.push({s[i],1});
                }
            }
        }
        string res;
        while(!st.empty()) {
            char ch = st.top().first;
            int count = st.top().second;
            res.push_back(ch);
            res.push_back(count + '0');
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};