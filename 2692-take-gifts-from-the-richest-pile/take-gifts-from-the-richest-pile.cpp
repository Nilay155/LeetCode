#define ll long long int
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<pair<int,int>> pq;

        for(int i = 0 ; i < n ; i++) pq.push({gifts[i],i});

        ll ans = 0;
        while(k--) {
            auto p = pq.top();
            pq.pop();

            int val = floor(sqrt(p.first));
            int l = p.second;
            gifts[l] = val;
            pq.push({val,l});
        }

        for(int i = 0 ; i < n ; i++) ans += gifts[i];
        return ans;
    }
};