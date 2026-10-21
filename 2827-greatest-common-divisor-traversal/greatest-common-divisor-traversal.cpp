class Solution {
public:
    static const int MAXA = 100000;

    vector<int> spf;

    void buildSPF() {
        spf.resize(MAXA + 1);
        iota(spf.begin(), spf.end(), 0);

        for (int i = 2; i * i <= MAXA; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXA; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    struct DSU {
        vector<int> parent, sz;

        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            sz.assign(n, 1);
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) return;

            if (sz[a] < sz[b]) swap(a, b);

            parent[b] = a;
            sz[a] += sz[b];
        }
    };

    bool canTraverseAllPairs(vector<int>& arr) {
        int n = arr.size();

        if (n <= 1) return true;

        buildSPF();

        DSU dsu(n);
        vector<int> first(MAXA + 1, -1);

        for (int i = 0; i < n; i++) {
            int x = arr[i];

            while (x > 1) {
                int p = spf[x];

                if (first[p] == -1) {
                    first[p] = i;
                } else {
                    dsu.unite(i, first[p]);
                }

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        long long pairs = 0;
        vector<long long> freq(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            int root = dsu.find(i);
            pairs += freq[root];
            freq[root]++;
        }

        long long totalPairs = 1LL * n * (n - 1) / 2;

        return pairs == totalPairs;
    }
};