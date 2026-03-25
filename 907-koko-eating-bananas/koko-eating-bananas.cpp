class Solution {
private:
    bool check(vector<int> &piles,int h,int k) {
        int n = piles.size();
        int time = 0;

        for(int i = 0 ; i < n ; i++) {
            int q = piles[i] / k;
            int r = (piles[i] % k != 0 ? 1 : 0);
            time += (q + r);
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long ts = 0;
        for(int p : piles) ts += p;

        long long s = 1, e = ts;
        while(s <= e) {
            long long mid = s + (e - s) / 2;

            if(check(piles,h,mid))
                e = mid - 1;
            else
                s = mid + 1;
        }
        return s;
    }
};