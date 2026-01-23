class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int m = target.size();
        vector<string> ans;
        stack<int> st;
        unordered_map<int,bool> mpp;
        for(int i = 0 ; i < m ; i++) mpp[target[i]] = true;

        int k = 0;
        for(int stream = 1 ; stream <= min(target[m-1],n); stream++) {
            st.push(stream);
            ans.push_back("Push");

            while(!st.empty() && mpp.find(st.top()) == mpp.end()) {
                st.pop();
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};