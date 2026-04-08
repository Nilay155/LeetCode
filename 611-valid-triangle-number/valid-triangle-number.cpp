class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return 0;
        
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i = 0 ; i < n - 2 ; i++) {
            int j = n - 2, k = n - 1;
            // i,j,k three pointers pointing at 3 sides of the triangle
            
            while(i < j && j < k) {

                if(nums[i] + nums[j] <= nums[k]) {
                    k -= 1;
                    if(j == k) j -= 1;
                } else {
                    // nums[i] + nums[j] > nums[k]
                    count += (k - j);
                    j -= 1;
                }
            }
        }
        return count;
    }
};