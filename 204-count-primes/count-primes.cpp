class Seive{
public:
    vector<bool> seive;
    Seive(int n) {
        seive.resize(n+1,true);
        seive[0] = seive[1] = false;
        for(int i = 2 ; i <= n ; i++) {
            if(!seive[i]) continue;
            for(long long j = 1LL*i*i ; j <= n ; j += i) {
                seive[j] = false;
            }
        }
    }    
};
class Solution {
public:
    int countPrimes(int n) {
        Seive arr(n);
        int count = 0;
        for(int i = 2 ; i < n ; i++) {
            if(arr.seive[i]) count += 1;
        }
        return count;
    }
};