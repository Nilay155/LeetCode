class Solution {
private:
    int rectangle(vector<vector<int>> &matrix,int i) {
        int n = matrix.size(), m = matrix[0].size();
        stack<int> st;
        vector<int> nse(m,m), pse(m,-1);

        for(int j = 0 ; j < m ; j++) {
            while(!st.empty() && matrix[i][st.top()] >= matrix[i][j]) {
                st.pop();
            }
            if(!st.empty())
                pse[j] = st.top();
            st.push(j);
        }
        st = stack<int> ();
        for(int j = m-1 ; j >= 0 ; j--) {
            while(!st.empty() && matrix[i][st.top()] >= matrix[i][j]) {
                st.pop();
            }
            if(!st.empty())
                nse[j] = st.top();
            st.push(j);
        }

        int maxRectangle = 0;
        for(int j = 0 ; j < m ; j++) {
            int ns = nse[j],ps = pse[j];
            int left = j - ps, right = ns - j;
            int breadth = left + right - 1;
            int length = matrix[i][j];
            maxRectangle = max(maxRectangle,length * breadth);
        }
        return maxRectangle;
    }
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> matrix(n,vector<int>(m));
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                matrix[i][j] = mat[i][j] - '0';
        int maxRectangle = 0;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(i > 0) {
                    if(matrix[i][j] > 0) 
                        matrix[i][j] += matrix[i - 1][j];
                }
                maxRectangle = max(maxRectangle,rectangle(matrix,i));
            }
        }
        return maxRectangle;
    }
};