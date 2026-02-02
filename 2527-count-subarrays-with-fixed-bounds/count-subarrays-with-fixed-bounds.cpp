class Solution {
public:
long long countSubarrays(const std::vector<int>& nums, int minK, int maxK) {
    int n = nums.size();
    multiset<int> mst;
    unordered_map<int,int> index;
    int l = 0, r = 0;
    long long ans = 0;
    
    while(r < n) {
        mst.insert(nums[r]);
        index[nums[r]] = r;
        
        int mini = *mst.begin();
        int maxi = *mst.rbegin();
        
        while(l <= r && (mini < minK || maxi > maxK)) {
            auto it = mst.find(nums[l]);
            mst.erase(it);
            if(mst.find(nums[l]) == mst.end()) 
                index.erase(nums[l]);
            l += 1;
            
            if(mst.empty()) break;
            mini = *mst.begin();
            maxi = *mst.rbegin();
        }
        if(mini == minK && maxi == maxK) {
            int k1 = index[minK], k2 = index[maxK];
            int smallest = min(k1,k2);
            ans += (smallest - l + 1);
        }
        r += 1;
    }
    return ans;
}
};