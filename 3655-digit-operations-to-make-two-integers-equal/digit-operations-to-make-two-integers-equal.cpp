class Solution {
public:
    int minOperations(int n, int m) {
        int limit = 9999;
        vector<bool> isPrime(limit + 1,true);
        isPrime[0] = isPrime[1] = false;
        for(int p = 2 ; p <= limit ; p++) {

            if(isPrime[p]) {
                for(int j = 2 * p ; j <= limit ; j += p) {
                    isPrime[j] = false;
                }
            }
        }

        if(isPrime[n])
            return -1;
        if(isPrime[m])
            return -1;
        

        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> q;
        q.push({n,to_string(n)});
        vector<bool> vis(limit + 1,false);
        vis[n] = true;
        while(!q.empty()) {
            
                auto [cost,top] = q.top(); q.pop();
                // cout << top << "\b";
                if(stoi(top) == m)
                    return cost;

                
                for(int i = 0 ; i < (int) top.length() ; i++) {
                    // Increment
                    string next = top;
                    if (top[i] != '9') {
                        next[i] = (char)(top[i] + 1);

                        int num = stoi(next);
                        if (!vis[num] && !isPrime[num]) {
                            vis[num] = true;
                            q.push({num + cost,next});
                        }
                    }
                    next = top;
                    // Decrement
                    if (top[i] != '0') {
                        if(top[i] == '1' && i == 0) 
                            continue;
                        next[i] = (char)(top[i] - 1);
                        int num = stoi(next);
                        if (!vis[num] && !isPrime[num]) {
                            vis[num] = true;
                            q.push({num + cost,next});
                        }
                    }
                }
        
        }
        return -1;
    }
};