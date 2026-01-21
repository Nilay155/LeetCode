class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int maximalArea = 0;
        vector<vector<int>> matrix(n,vector<int>(m));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                matrix[i][j] = mat[i][j] - '0';
            }
        }
        for(int i = 1 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        for(int i = 0 ; i < n ; i++) {

            vector<int> nse(m,m), pse(m,-1);
            stack<int> st;

            // computing the prev smaller element
            for(int j = 0 ; j < m ; j++) {
                while(!st.empty() && matrix[i][j] <= matrix[i][st.top()]) {
                    st.pop();
                }
                if(!st.empty()) pse[j] = st.top();
                st.push(j);
            }
            st = stack<int>();
            // computing the next smallest element
            for(int j = m-1 ; j >= 0 ; j--) {
                while(!st.empty() && matrix[i][j] <= matrix[i][st.top()]) {
                    st.pop();
                }
                if(!st.empty()) nse[j] = st.top();
                st.push(j);
            }

            for(int j = 0 ; j < m ; j++) {
                int l = pse[j], r = nse[j];
                int breadth = (r - l) - 1;
                int length = matrix[i][j];
                maximalArea = max(maximalArea,length * breadth); 
            }
        }
        return maximalArea;
    }
};