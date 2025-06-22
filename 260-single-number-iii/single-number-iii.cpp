class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int num : nums) mpp[num] += 1;
        int first = INT_MAX,second = INT_MAX;

        for(auto& it : mpp) {   
            if(it.second == 1) {
                if(first != INT_MAX) second = it.first;
                else first = it.first;
            }
        } 
        if(first > second) return {second,first};
        else return {first,second};
    }
};