typedef long long ll;
class Solution {
private:
ll baseConversion(ll mid, int len, ll target) {
    ll num = 1;   // sum
    ll curr = 1;  // mid^i

    for (int i = 1; i < len; i++) {
        // prevent overflow AND useless work
        if (curr > target / mid) return target + 1;
        curr *= mid;

        num += curr;
        if (num > target) return target + 1;
    }

    return num;
}
public:
    string smallestGoodBase(string n) {
        ll ans = 1e18, num = stoll(n);
        for(int len = 1 ; len <= 64 ; len++) {
            ll l = 2, r = 1e18;
            while(l <= r) {
                ll mid = l + (r - l) / 2;
                ll val = baseConversion(mid,len,num);
                if(val >= num){
                    if(val == num) {
                        ans = min(ans,mid);
                    }
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } 
        }
        return to_string(ans);
    }
};