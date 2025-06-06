class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        stack<int> st;

        for(int i = 0 ; i < n ; i++) pq.push({s[i]-'a',i});
        
        int last = -1;
        string ans;
        while(!pq.empty()) {
            
            auto [pos,idx] = pq.top(); pq.pop();

            if(idx <= last) {
                continue;
            }

            while(!st.empty() && (st.top() <= pos)) {
                ans.push_back('a' + st.top());
                st.pop();
            }

            ans.push_back('a' + pos);

            for(int k = last+1 ; k < idx ; k++) {
                st.push(s[k]-'a');
            }
            last = idx;
        }
        while(!st.empty()) {
            ans.push_back('a' + st.top());
            st.pop();
        }
        return ans;
    }
};