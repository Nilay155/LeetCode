class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int match = INT_MAX;
        int chunks = 0;

        for(int i = n-1 ; i >= 0 ; i--) {
            match = min(match,arr[i]);
            
            if(match == i) {
                chunks += 1;
            }
        }
        return chunks;
    }
};