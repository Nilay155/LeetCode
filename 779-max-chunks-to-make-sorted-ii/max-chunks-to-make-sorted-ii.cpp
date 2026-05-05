class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> nums = arr;
        sort(nums.begin(),nums.end());
        int i = 0, p = -1, chunks = 0;

        for(int i = 0 ; i < n ; i++) {
            unordered_map<int,int> freq;
            for(int j = p + 1 ; j <= i ; j++) {
                freq[nums[j]] += 1;
            }
            for(int j = p + 1 ; j <= i ; j++) {
                freq[arr[j]] -= 1;
            }
            bool flag = true;
            for(auto [e,f] : freq) {
                if(f > 0 || f < 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                p = i;
                chunks += 1;
            }
        }
        return chunks;
    }
};