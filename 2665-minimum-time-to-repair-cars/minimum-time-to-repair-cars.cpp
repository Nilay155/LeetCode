typedef long long ll;
class Solution {
private:
    bool check(vector<int> &ranks,int cars,long long mid) {
        int n = ranks.size();

        long long count = 0;
        for(int i = 0 ; i < n ; i++) {
            long long temp = (mid/ranks[i]);
            long long cnt = sqrt(temp);
            count += cnt;
        }
        return count >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // A mechanic with a rank r can repair n cars in r * n^2 minutes.
        // cars representing the total number of cars waiting in the garage to be repaired.
        int n = ranks.size();
        sort(ranks.begin(),ranks.end());

        long long low = ranks[0];
        long long high = 1LL*ranks[n-1]*cars*cars;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            if(check(ranks,cars,mid)) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};