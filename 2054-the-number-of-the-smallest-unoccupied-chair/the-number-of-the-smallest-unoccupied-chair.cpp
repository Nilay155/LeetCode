class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();
        vector<vector<int>> nums;
        for(int i = 0 ; i < n ; i++) {
            int s = times[i][0], e = times[i][1];
            nums.push_back({s,e,i});
        }
        sort(nums.begin(),nums.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> occupied;
        priority_queue<int,vector<int>,greater<int>> freeChairs;
        for(int i = 0 ; i < n ; i++) freeChairs.push(i);

        int ans = -1;
        for(int i = 0 ; i < n ; i++) {
            int s = nums[i][0], e = nums[i][1], index = nums[i][2];
            while(!occupied.empty() && occupied.top().first <= s) {
                freeChairs.push(occupied.top().second);
                occupied.pop();
            }

            occupied.push({e,freeChairs.top()});
            if(targetFriend == index) ans = freeChairs.top();
            freeChairs.pop();
        }
        return ans;

    }
};