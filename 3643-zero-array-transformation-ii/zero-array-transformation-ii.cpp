class Solution {
private:
    bool func(vector<int> &nums,vector<vector<int>>& queries,int start,int end) {
        int n = nums.size();
        vector<int> temp(n,0);
        for(int i = start ; i <= end ; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            if(l >= n || l < 0) continue;

            if(r+1 < n) temp[r+1] += val;
            temp[l] -= val;
        }
        for(int i = 1;  i < n ; i++) temp[i] = temp[i] + temp[i-1];
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] + temp[i] > 0)  {
                return false;
            }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = nums.size();
        
        int low = 0, high = m-1;
        int k = INT_MAX;
        int flag = false;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] > 0) {
                flag = true;
                break;
            }
        }
        if(!flag) return 0;
        
        while(low <= high) {
            int mid = (low + high) >> 1;

            if(func(nums,queries,0,mid)) {
                high = mid-1;
                k = min(k,mid+1);
            } else {
                low = mid+1;
            }
        }
        return k == INT_MAX ? -1 : k;
    }
};