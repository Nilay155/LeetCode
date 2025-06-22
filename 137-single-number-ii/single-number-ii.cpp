class Solution {
private:
    int func1(vector<int> &nums) {
        unordered_map<int,int> mpp;
        for(int num : nums) mpp[num]++;
        for(auto& it : mpp) {
            if(it.second == 1) return it.first;
        }
        return -1;
    }
    // int func2(vector<int> &nums) {
    // }
    // int func3(vector<int> &nums) {
    // }
    // int func4(vector<int> &nums) {
    // }
public:
    int singleNumber(vector<int>& nums) {
        return func1(nums);
        // return func2(nums);
        // return func3(nums);
        // return func4(nums);
    }
};