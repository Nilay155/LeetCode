class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> count;

        for(int num : nums) count[num]++;

        int dominantElement = -1;
        for(auto& it : count) {
            if(it.second > n/2) {
                dominantElement = it.first;
                break;
            }
        }

        int minIndex = -1;
        int cnt = 0;
        int total = count[dominantElement];

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == dominantElement) cnt += 1;

            if((i+1)/2 < cnt && (n-i-1)/2 < total-cnt) return i;
        }
        return minIndex;
    }
};