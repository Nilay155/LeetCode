class Solution {
private:
    long long nSum(int k) {
        long long u = k, v = k + 1;
        if(u % 2 == 0) u /= 2;
        else v /= 2;
        return (u * v); 
    }
    bool check(int val,int index,int n,int maxSum) {
        long long le = index, re = n - index - 1;

        long long ts = nSum(val - 1);
        long long ls = ts - nSum(max(0LL,val - le - 1));
        long long rs = ts - nSum(max(0LL,val - re - 1));
        
        if(ls + rs + val <= maxSum) return true;
        else return false;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int s = 0, e = maxSum;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(check(mid,index,n,maxSum)) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return s;
    }
};