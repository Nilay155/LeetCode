class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> nums = arr;
        sort(nums.begin(),nums.end());
        int chunks = 0, j = 0;

        // O(n ^ 2) approach
        // for(int i = 0 ; i < n ; i++) {
            // unordered_map<int,int> freq;
            // for(int j = p + 1 ; j <= i ; j++) {
            //     freq[nums[j]] += 1;
            // }
            // for(int j = p + 1 ; j <= i ; j++) {
            //     freq[arr[j]] -= 1;
            // }
            // bool flag = true;
            // for(auto [e,f] : freq) {
            //     if(f > 0 || f < 0) {
            //         flag = false;
            //         break;
            //     }
            // }
            // if(flag) {
            //     p = i;
            //     chunks += 1;
            // }
        // }

        // O(n) optimization
        // multiset<int> mst;
        unordered_map<int,int> freq;
        for(int i = 0 ; i < n ; i++) {
            freq[arr[i]] += 1;
            while(j <= i && freq.find(nums[j]) != freq.end()) {
                freq[nums[j]] -= 1;
                if(freq[nums[j]] == 0)
                    freq.erase(nums[j]);
                j += 1;
            }
            if(j > i) chunks += 1;
        }
        return chunks;
    }
};