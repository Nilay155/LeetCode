class Solution {
private:
    bool isPossible(vector<int> &nums,int m,int k) {
        int n = nums.size();

        for(int i = 0 ; i <= m ; i++) {
            int r = m - i;
            int k1 = nums[i];
            int k2 = nums[n - r - 1];
            if((long long)k1*k >= (long long)k2) return true;
        }
        return false;
    }
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        int s = 0, e = n-1;
        sort(nums.begin(),nums.end());
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(isPossible(nums,mid,k)) {
                e = mid - 1;
            }  else {
                s = mid + 1;
            }
        }
        return s;
    }
};