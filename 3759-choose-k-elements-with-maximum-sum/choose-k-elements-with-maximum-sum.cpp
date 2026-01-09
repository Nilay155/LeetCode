typedef long long ll;
class Solution {
private:
    int findIndex(vector<vector<int>> &arr,int pos) {
        int s = 0, e = pos - 1;

        while(s <= e) {
            int mid = s + (e-s)/2;
            if(arr[mid][0] > arr[pos][0]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return e;
    }
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums2.size();

        vector<vector<int>> arr;
        for(int i = 0 ; i < n ; i++) arr.push_back({nums1[i],i});
        
        sort(arr.begin(),arr.end());
        
        vector<int> nums(n);
        for(int i = 0 ; i < n ; i++) nums[i] = nums2[arr[i][1]];

        ll sum = 0;
        priority_queue<int,vector<int>,greater<int>> pq;

        int l = 0, r = 0;
        vector<ll> ans(n);

        while(r < n) {
            // cout << sum <<"\n";
            while(r + 1 < n && arr[r][0] == arr[r+1][0]) {
                ans[arr[r][1]] = sum;
                r += 1;
            }
            ans[arr[r][1]] = sum;
            while(l <= r) {

                if(pq.size() >= k) {
                    int curr = pq.top(); 
                    if(curr < nums[l]) {
                        pq.pop();
                        sum -= curr;
                        sum += nums[l];
                        pq.push(nums[l]);
                    }
                } else {
                    sum += nums[l];
                    pq.push(nums[l]);
                }
                l += 1;
            }
            r += 1;
        } 
        return ans;
    }
};