class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();

        stack<int> st;
        for(int i = 0 ; i < n ; i++) {
            int val = asteroids[i];

            while(!st.empty() && val < 0 && st.top() >= 0 && abs(val) > st.top()) {
                st.pop();
            }

            if(val >= 0) {
                st.push(val);
            }
            else {
                if(!st.empty() && abs(val) == st.top()) st.pop();
                else if(!st.empty() && st.top() >= 0);
                else st.push(val);
            }
            
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};