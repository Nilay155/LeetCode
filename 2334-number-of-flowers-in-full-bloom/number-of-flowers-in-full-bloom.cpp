class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int> start,end;
        for(int i = 0 ; i < n ; i++) {
            int s = flowers[i][0], e = flowers[i][1];
            start.push_back(s);
            end.push_back(e);
        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int> ans;
        for(int t : people) {
            int started = upper_bound(start.begin(), start.end(), t) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
            ans.push_back(started - ended);
        }
        return ans;
    }
};