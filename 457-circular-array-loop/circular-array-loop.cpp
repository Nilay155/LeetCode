class Solution {
private:
    bool check(unordered_map<int,pair<int,bool>> &next,int curr,int prev,vector<bool> &vis) {
        if(next.find(curr) == next.end()) return false;
        if(vis[curr]) return true;

        vis[curr] = true;
        bool ans = false;
        if(prev == -1 || next[prev].second == next[curr].second) 
            ans = ans | check(next,next[curr].first,curr,vis);
        return ans;
    }
    bool detectCycle(unordered_map<int,pair<int,bool>> &nextPosition,int n) {
        bool ans = false;
        for(int i = 0 ; i < n ; i++) {
            vector<bool> vis(n,false);
            ans = ans | check(nextPosition,i,-1,vis);
        }
        return ans;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,pair<int,bool>> nextPosition;
        for(int i = 0 ; i < n ; i++) {
            int nextIndex = (((i + nums[i]) % n) + n) % n;
            if(i == nextIndex) continue; // self loop
            nextPosition[i] = {nextIndex,(nums[i] < 0 ? false : true)};
        }
        return detectCycle(nextPosition,n);
    }
};