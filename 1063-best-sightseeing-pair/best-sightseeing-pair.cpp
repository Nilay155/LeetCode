class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // i < j
        // values[i] + values[j] + i - j
        // return maximum score
        // Brute Force -> O(n^2)
        // Optimal Soln -> O() ???
        int n = values.size();
        priority_queue<pair<int,int>> pq;
        for(int i = 0 ; i < n ; i++) {
            int val = values[i] - i;
            pq.push({val,i});
            cout << val << endl;
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            
            int val = i + values[i];
            while(!pq.empty() && pq.top().second <= i) pq.pop();
            if(pq.empty()) break;
            auto p = pq.top();
            ans = max(ans,val + p.first);
            
        }
        return ans;
    }
};