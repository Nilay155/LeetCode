typedef long long ll;
class Solution {
private:
    bool check(vector<int> &batt,ll mid,ll cn) {
        int m = batt.size();
        ll count = 0, sum = 0;

        for(int i = 0 ; i < m ; i++) {
            
            if(sum + batt[i] < mid) {
                sum += batt[i];
            } else { // sum + batt[i] >= mid
                ll diff = sum + batt[i] - mid;
                count += 1;
                sum = diff;
            }
        }
        return count >= cn;
    }
public:
    long long maxRunTime(int n, vector<int>& batt) {
        ll m = batt.size(), ts = 0;
        for(int b : batt) ts += b;
        sort(batt.begin(),batt.end());
        ll s = 0, e = ts;
        while(s <= e) {
            ll mid = s + (e - s) / 2;
            if(check(batt,mid,n)) 
                s = mid + 1;
            else
                e = mid - 1;
        }
        return e;
    }
};