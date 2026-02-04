typedef long long ll;
class Solution {
private:
    tuple<ll,ll,ll> increasing(vector<int> &nums,int s) {

        int k = s, n = nums.size();
        while(k < n && nums[k-1] < nums[k]) k++;
        // [a valid range from s to k-1]
        ll sum = nums[k-1],max1 = -1e18,max2 = -1e18;
        for(int i = k-2 ; i >= s-1 ; i--) {
            sum += nums[i];
            max1 = max(max1,sum); 
        }
        sum = 0;
        for(int i = s ; i <= k-1 ; i++) {
            sum += nums[i];
            max2 = max(max2,sum);
        }
        return {max1,max2,k};
    }
    tuple<ll,ll> decreasing(vector<int> &nums,int s) {
        int n = nums.size();
        int k = s;
        while(k < n && nums[k] < nums[k-1]) k++;
        ll sum = 0;
        for(int i = k-1 ; i >= s ; i--) {
            sum += nums[i];
        }
        return {sum,k};
    }
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        ll p = -1, q = -1, pSum = 0, qSum = 0;
        ll ans = -1e18;
        while(i < n) {
            if(nums[i] > nums[i-1]) { // increasing segement
                auto [m1,m2,k] = increasing(nums,i);
                if(p == -1) {
                    p = k-1, pSum = m1;
                    // cout << p << "   " << pSum << "\n";
                } else if(p != -1 && q != -1 && p < q) { // two distinct p,q high and low
                    ans = max(ans,m2 + pSum + qSum);
                    p = k-1, q = -1, qSum = -1e15;
                    pSum = m1;
                    // cout << p << "  " << pSum << "  " << qSum << "  " << m2 << "\n";
                }
                i = k;
            } else if(nums[i] < nums[i-1]){ // decreasing segement
                auto [m,k] = decreasing(nums,i);
                if(p != -1 && q == -1) {
                    q = k-1;
                    qSum = m;
                    // cout << q << "   " << qSum << "\n";
                }
                i = k;
            } else {
                p = -1, q = -1, pSum = 0, qSum = 0;
                i += 1;
            }
        }
        return ans;
    }
};