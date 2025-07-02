class Solution {
private: 
    int largestRectangle(vector<int> &heights) {
        int n = heights.size();
        vector<int> prevSmallest(n),nextSmallest(n);
        stack<int> st;
        st.push(-1);

        for(int i = 0 ; i < n ; i++) {

            while(!st.empty() && st.top() != -1 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            prevSmallest[i] = st.top();
            st.push(i);
        }

        st = stack<int>();
        st.push(n);
        
        for(int i = n-1 ; i >= 0 ; i--) {
            while(!st.empty() && st.top() != n && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nextSmallest[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            int breadth = nextSmallest[i]-prevSmallest[i]-1;
            int length = heights[i];

            ans = max(ans,breadth * length);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prefix(n);
        int ans = 0;
        for(int i = 0 ; i < m ; i++) {

            vector<int> nums;
            for(int j = 0 ; j < n ; j++) {
                if(matrix[i][j] == '1') {
                    prefix[j] = 1 + prefix[j];
                } else {
                    prefix[j] = 0;
                }
                nums.push_back(prefix[j]);
            }
            ans = max(ans,largestRectangle(nums));
        }
        return ans;
    }
};