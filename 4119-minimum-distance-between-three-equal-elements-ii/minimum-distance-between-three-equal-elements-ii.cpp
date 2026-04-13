class Solution {
private:
    int distance(int i,int j,int k) {
        return abs(i - j) + abs(j - k) + abs(k - i);
    }
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), minDistance = 1e9;

        unordered_map<int,vector<int>> indexes;
        for(int i = 0 ; i < n ; i++)
            indexes[nums[i]].push_back(i); 
        
        for(auto [ele,arr] : indexes) {

            int m = arr.size();
            if(m <= 2) continue;
            
            int i = 0, j = 1;
            
            for(int k = 2 ; k < m ; k++) {
                minDistance = min(minDistance,distance(arr[i],arr[j],arr[k]));
                i += 1, j += 1;
            }
        }
        return minDistance == 1e9 ? -1 : minDistance;
    }  
};