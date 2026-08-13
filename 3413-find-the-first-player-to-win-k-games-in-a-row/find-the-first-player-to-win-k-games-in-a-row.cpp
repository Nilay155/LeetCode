class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        if(k >= n) k = n - 1;

        stack<int> st;
        vector<int> nextGreaterElement(n,n);
        st.push(n - 1);

        for(int i = n - 2 ; i >= 0 ; i--) {
            while(!st.empty() && skills[st.top()] < skills[i])
                st.pop();
            
            if(!st.empty())
                nextGreaterElement[i] = st.top();
            st.push(i);
        }

        int maxi = 0;
        for(int i = 0 ; i < n ; i++) {
            int nge = nextGreaterElement[i];
            int curr = skills[i];
            int wins = 0;

            if(curr > maxi && maxi != 0)
                wins = 1;
            else if(maxi > curr)
                continue;


            wins += (nge - i - 1);
            if(nge == n)
                wins = n;
            if(wins >= k)
                return i;

            maxi = max(maxi,curr);
        }
        return 0;
    }
};