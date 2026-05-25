class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows == 1) return s;

        vector<vector<int>> rows(numRows);
        int k = 0, v = 0;

        for(int i = 0 ; i < n ; i++) {
            rows[k].push_back(i);
            
            if(!v) k += 1;
            else k -= 1;

            if(k == numRows) {
                v = 1, k = numRows - 2;
            }
            if(k == -1) {
                v = 0, k = 1;
            }
        }
        string ans;
        for(int i = 0 ; i < numRows ; i++) {
            for(int j = 0 ; j < rows[i].size() ; j++) {
                ans.push_back(s[rows[i][j]]);
            }
        }
        return ans;
    }
};