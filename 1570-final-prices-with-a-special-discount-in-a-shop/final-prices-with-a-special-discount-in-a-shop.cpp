class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer(n);

        stack<int> st; // next recent smallest element
        for(int i = n-1 ; i >= 0 ; i--) {
            
            while(!st.empty() && prices[st.top()] > prices[i]) {
                st.pop();
            }
            int discount = 0;
            if(!st.empty()) discount = prices[st.top()];
            answer[i] = prices[i] - discount;
            st.push(i);
        }
        return answer;
    }
};