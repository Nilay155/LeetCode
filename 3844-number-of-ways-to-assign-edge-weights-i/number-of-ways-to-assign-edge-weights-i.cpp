// class Factorial{
// public:
//     vector<long long int> fact;
//     Factorial(int n) {
//         fact.resize(n+1,1);
//         long long int MOD = 1e18;
//         for(int i = 1 ; i <= n ; i++) {
//             fact[i] = (1LL * fact[i-1] * i)%MOD;
//         }
//     }
// };
class Factorial {
public:
    vector<long long> fact, invFact;
    const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while(b) {
            if(b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    Factorial(int n) {
        fact.resize(n+1, 1);
        invFact.resize(n+1, 1);

        for(int i = 1; i <= n; ++i)
            fact[i] = (fact[i-1] * i) % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);
        for(int i = n - 1; i >= 0; --i)
            invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }

    long long nCk(int n, int k) {
        if(k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }
};

class Solution {
private:
    void dfs(int src,vector<vector<int>> &graph,vector<int> &maxDepth,vector<bool> &vis,int depth) {
        vis[src] = true;
        maxDepth[src] = max(maxDepth[src],depth);

        for(int child : graph[src]) {
            if(!vis[child]) dfs(child,graph,maxDepth,vis,depth+1);
        }
        vis[src] = false;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
       // from 1 to x having maximum depth
       int n = edges.size();
       vector<vector<int>> graph(n+2);

       for(auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
       }
       int MOD = 1e9 + 7;

       vector<int> maxDepth(n+2,0);
       vector<bool> vis(n+2,false);
       dfs(1,graph,maxDepth,vis,0); 
       
       int maxi = INT_MIN;
       for(int depth : maxDepth) maxi = max(maxi,depth);

       // 1 or 2 as weights
       // o + o = e , e + e = o, e + o = o, o + e = o
    //    Factorial arr(maxi);

    //    long long int ways = 0; 
    //    for(int i = 1 ; i <= maxi ; i++) {
    //     long long int x = (i)*1; // odd weights
    //     long long int y = (maxi-i)*2; // even weights
        
    //     if((x+y)%2 == 1) {
    //         long long int temp = (arr.fact[maxi]/(arr.fact[i]*arr.fact[maxi-i]));
    //         ways = (ways + temp) % MOD;
    //     }
    //    }
    //    return ways;

    Factorial arr(maxi); // use MOD 1e9+7 internally now

    long long ways = 0;
    for(int i = 1; i <= maxi; i++) {
        int x = i * 1; // odd weights
        int y = (maxi - i) * 2; // even weights

        if ((x + y) % 2 == 1) {
            long long temp = arr.nCk(maxi, i);
            ways = (ways + temp) % MOD;
        }
    }
    return ways;
    }
};