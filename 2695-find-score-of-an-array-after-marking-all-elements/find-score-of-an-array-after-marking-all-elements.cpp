#define ll long long int
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0 ; i < n ; i++) pq.push({nums[i],i});

        vector<bool> vis(n,0);

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int val = p.first;
            int k = p.second;

            if(!vis[k]) {
                ans += val;
                if(k+1 < n) vis[k+1] = 1;
                if(k-1 >= 0) vis[k-1] = 1;
                vis[k] = 1;
                
            }
        }
        return ans;
    }
};