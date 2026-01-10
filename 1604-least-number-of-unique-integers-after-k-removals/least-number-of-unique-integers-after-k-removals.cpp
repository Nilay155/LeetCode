class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++) mpp[arr[i]]++;

        vector<int> counts;
        for(auto [val,count] : mpp) counts.push_back(count);
        sort(counts.begin(),counts.end());

        int i;
        for(i = 0 ; i < counts.size() ; i++) {
            if(counts[i] <= k) {
                k -= counts[i];
            } else {
                break;
            }
        }
        return counts.size() - i;

    }
};