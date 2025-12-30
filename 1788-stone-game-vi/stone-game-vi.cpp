class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<pair<int,int>> sum(n);
        for(int i = 0 ; i < n ; i++) {
            sum[i].first = a[i] + b[i];
            sum[i].second = i;
        }
        sort(sum.rbegin(),sum.rend());
        int p = 0;
        for(int i = 0 ; i < n ; i++) {
            auto [val,k] = sum[i];
            if(i%2 == 0) p += a[k];
            else p -= b[k];
        }
        if(p == 0) return 0;
        else if(p > 0) return 1;
        else return -1;
    }
};