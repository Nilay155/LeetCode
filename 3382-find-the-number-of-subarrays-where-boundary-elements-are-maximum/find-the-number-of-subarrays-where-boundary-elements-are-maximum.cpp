typedef long long ll;

class SparseTable {
private:
    int n;
    vector<vector<int>> st;   // st[i][j] = max in range [i, i + 2^j - 1]
    vector<int> log2val;

public:
    SparseTable(const vector<int>& arr) {
        n = arr.size();

        // Precompute logs
        log2val.resize(n + 1);
        log2val[1] = 0;
        for (int i = 2; i <= n; i++)
            log2val[i] = log2val[i / 2] + 1;

        int K = log2val[n] + 1;
        st.assign(n, vector<int>(K));

        // Base case: intervals of length 1
        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];

        // Build table
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j - 1],
                               st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // Query maximum in range [l, r]
    int query(int l, int r) {
        int len = r - l + 1;
        int j = log2val[len];
        return max(st[l][j],
                   st[r - (1 << j) + 1][j]);
    }
};

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        SparseTable st(nums);

        unordered_map<int,pair<int,ll>> subArrays;
        ll ans = 0;
        for(int i = 0 ; i < n ; i++) {
            
            if(subArrays.find(nums[i]) != subArrays.end()) {
                auto [prevIndex, count] = subArrays[nums[i]];
                int currIndex = i;

                int mx = st.query(prevIndex,currIndex);
                if(mx == nums[i]) {
                    subArrays[nums[i]] = {i , count + 1};
                } else {
                    subArrays[nums[i]] = {i , 0};
                }
                ans += subArrays[nums[i]].second + 1;
            } else {
                subArrays[nums[i]] = {i, 0};
                ans += subArrays[nums[i]].second + 1;
            }
        }
        return ans;
    }
};