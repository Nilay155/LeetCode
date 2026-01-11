class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        int n = queries.size();
        vector<int> ans(n);
        unordered_map<int,int> colors, ballColor; // [y -> no of x's]
        for(int i = 0 ; i < n ; i++) {
            int x = queries[i][0], y = queries[i][1];
            
            if(ballColor.find(x) != ballColor.end()) {
                // means this ball has been previously covered in some other color
                int prevColor = ballColor[x];
                colors[prevColor] -= 1;
                if(colors[prevColor] <= 0)
                    colors.erase(prevColor);
            }
            if(colors.find(y) != colors.end()) {
                colors[y] += 1;
                ballColor[x] = y;
            } else {
                colors.insert({y,1});
                ballColor[x] = y;
            }
            ans[i] = colors.size();
        }
        return ans;
    }
};