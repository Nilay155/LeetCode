class Solution {
private:
    int distance(int i,int j,int k) {
        return abs(i - j) + abs(j - k) + abs(k - i);
    }
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), minDistance = 1e9;
        
        for(int i = 0 ; i < n - 2 ; i++) {
            for(int j = i + 1 ; j < n - 1 ; j++) {
                for(int k = j + 1 ; k < n ; k++) {

                    if(nums[i] == nums[j] && nums[j] == nums[k]) {
                        minDistance = min(minDistance,distance(i,j,k));
                    }
                }
            }
        }
        return minDistance == 1e9 ? -1 : minDistance;
    }
};