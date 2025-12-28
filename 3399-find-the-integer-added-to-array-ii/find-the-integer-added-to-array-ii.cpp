class Solution {
private:
    bool check(vector<int> &nums1,vector<int> &nums2,int x) {
        int i = 0, n = nums1.size();
        int j = 0, m = nums2.size();

        while(i < n && j < m) {

            if(nums1[i] + x == nums2[j]) {
                i++,j++;
            } else {
                i++;
            }
        }
        return (j == m) ? true : false;
    }
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ans = INT_MAX;
        for(int i = 0 ; i < 3 ; i++) {
            int x = nums2[0] - nums1[i];
            if(check(nums1,nums2,x)) {
                ans = min(ans,x);
            }
        }
        return ans;
    }
};