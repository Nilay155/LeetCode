class Solution {
private:
    // int func1(vector<int> &nums) {
    //     unordered_map<int,int> mpp;
    //     for(int num : nums) mpp[num]++;
    //     for(auto& it : mpp) {
    //         if(it.second == 1) return it.first;
    //     }
    //     return -1;
    // }
    // int func2(vector<int> &nums) {
    //     int ans = 0;
    //     for(int bitIndex = 0 ; bitIndex < 32 ; bitIndex++) {
    //         int count = 0;
    //         for(int num : nums) {
    //             if(num & (1 << bitIndex)) {
    //                 count += 1;
    //             }
    //         }
    //         if(count%3 == 1) {
    //             ans = ans | (1 << bitIndex);
    //         }
    //     }
    //     return ans;
    // }
    // int func3(vector<int> &nums) {

    //     sort(nums.begin(),nums.end());
        
    //     for(int k = 1 ; k < nums.size() ; k += 3) {
    //         if(nums[k] != nums[k-1]) return nums[k-1];
    //     }
    //     return nums[nums.size()-1];
    // }
    int func4(vector<int> &nums) {
        // count of buckets
        int ones = 0, twos = 0;

        for(int num : nums) {
            ones = (ones ^ num) & (~twos);
            twos = (twos ^ num) & (~ones);
        }
        return ones;
    }
public:
    int singleNumber(vector<int>& nums) {
        // return func1(nums);
        // return func2(nums);
        // return func3(nums);
        return func4(nums);
    }
};