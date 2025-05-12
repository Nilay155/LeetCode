class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        ans.push_back({1});
        int k = 1;

        while(k < numRows) {
            vector<int> temp;
            for(int j = 0 ; j <= k ; j++) {
                int res = 0;
                if(j-1 >= 0) res += ans[k-1][j-1];
                if(j < ans[k-1].size()) res += ans[k-1][j];
                temp.push_back(res);    
            }
            ans.push_back(temp);
            k++;
        }
        return ans;
    }
};