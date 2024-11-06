class Solution {
public:
    bool isSorted(vector<int> &nums) {

        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] < nums[i-1]) return 0;
        }
        return 1;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> bitCount;
        for(int num : nums) {
            bitCount[num] = bitset<32>(num).count();
        }

        // Bubble Sort
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n-1 ; j++) {
                if(nums[j] > nums[j+1] && bitCount[nums[j]] == bitCount[nums[j+1]]) {
                    swap(nums[j],nums[j+1]);
                }
            }
        }

        if(isSorted(nums)) return 1;
        else return 0;
    }
};