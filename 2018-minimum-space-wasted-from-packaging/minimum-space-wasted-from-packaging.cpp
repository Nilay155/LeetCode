typedef long long ll;

class Solution {
public:
    int minWastedSpace(vector<int>& p, vector<vector<int>>& b) {
        int n = p.size(), m = b.size(), mod = 1e9 + 7;

        ll minWaste = LLONG_MAX;  // FIX 1

        sort(p.begin(), p.end());
        for (int i = 0; i < m; i++) {
            sort(b[i].begin(), b[i].end());
        }

        int maxPackage = p[n - 1];
        for (int i = 0; i < m; i++) {
            maxPackage = max(maxPackage, b[i].back());
        }

        vector<ll> counts(maxPackage + 1, 0), sum(maxPackage + 1, 0);

        for (int pp : p) {
            counts[pp]++;
            sum[pp] += pp;
        }

        for (int k = 1; k <= maxPackage; k++) {
            counts[k] += counts[k - 1];
            sum[k] += sum[k - 1];
        }

        for (int i = 0; i < m; i++) {
            int z = b[i].size();
            if (p[n - 1] > b[i][z - 1]) continue;

            ll cost = 0, count = 0;

            for (int j = 0; j < z; j++) {
                int prev = (j > 0 ? b[i][j - 1] : 0);

                ll packages = counts[b[i][j]] - counts[prev];
                ll diffSum = sum[b[i][j]] - sum[prev];

                count += packages;

                // FIX 2: NO MOD HERE
                cost += (ll)b[i][j] * packages - diffSum;
            }

            if (count == n) {
                minWaste = min(minWaste, cost);
            }
        }

        // FIX 3: correct return
        return minWaste == LLONG_MAX ? -1 : (int)(minWaste % mod);
    }
};