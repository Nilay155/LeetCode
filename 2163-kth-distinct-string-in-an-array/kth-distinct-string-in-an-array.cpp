class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string,int> mpp;

        for(auto str : arr) {
            mpp[str]++;
        }

        for(auto& str : arr) {
            if(mpp[str] == 1) {
                k--;
                if(k == 0) return str;
            }
        }
        return "";
    }
};