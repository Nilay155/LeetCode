typedef long long ll;
class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        int n = w.size();
        // O(n*n*k) -> DP is not a feasable solution
        if(k == 1) return 0;

        vector<ll> partitionSums;
        for(int i = 0 ; i < n - 1 ; i++) 
            partitionSums.push_back(w[i] + w[i + 1]);
        
        sort(partitionSums.begin(),partitionSums.end());
        ll mini = 0;
        for(int i = 0 ; i < k - 1 ; i++) 
            mini += partitionSums[i];
        
        reverse(partitionSums.begin(),partitionSums.end());
        ll maxi = 0;
        for(int i = 0 ; i < k - 1 ; i++) 
            maxi += partitionSums[i];
 
        return maxi - mini;
    }
};