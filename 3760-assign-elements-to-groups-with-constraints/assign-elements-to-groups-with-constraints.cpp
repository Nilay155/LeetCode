class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        
        int n = groups.size(), m = elements.size();

        vector<int> ans(n,-1);
        int maxElement = 0;
        for(int i = 0 ; i < n ; i++) {
            maxElement = max(maxElement,groups[i]);
        }
        unordered_map<int,int> mapper;
        unordered_map<int,bool> vis;
        for(int i = 0 ; i < m ; i++) {
            int e = elements[i];
            if(vis.count(e)) continue;
            vis[e] = true;
            for(int j = e ; j <= maxElement ; j += e) {
                if(mapper.find(j) == mapper.end())
                    mapper[j] = i;
            }
        }
        for(int i = 0 ; i < n ; i++) {
            int g = groups[i];
            if(mapper.find(g) != mapper.end())
                ans[i] = mapper[g];
        }
        return ans;
    }
};