class Solution {
private:
    bool check(vector<int> &nums1,map<int,int> &mpp,int x) {
        map<int,int> count;
        for(int num : nums1) count[num + x]++;

        int k = 0;
        for(auto [val,cnt] : mpp) {
            if(count.find(val) != count.end()) {
                // means I have found a value
                if(count[val] >= mpp[val]) 
                    k += 1;
            }
        }
        if(k == mpp.size()) return true;
        else return false;
    }
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        map<int,int> mpp;
        for(int num : nums2) mpp[num]++;

        for(int x = -1000 ; x <= 1000 ; x++) {
            if(check(nums1,mpp,x)) return x;
        }
        return -1;
    }
};