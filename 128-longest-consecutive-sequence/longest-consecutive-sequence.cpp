class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int grpNumber = 1, ans = 0;

        unordered_map<int,int> groups; // grpNumber,grpSize
        unordered_map<int,int> vis; // element,grpNumber
        unordered_map<int,int> grpEndNumber; // grpNumber,elementEnding

        for(int i = 0 ; i < n ; i++) {
            int e = nums[i];
            if(vis.count(e)) continue;
            
            int le = e - 1, re = e + 1;
            bool l = false, r = false;
            if(vis.count(le)) {
                l = true;
                int currGrpNumber = vis[le];
                groups[currGrpNumber] += 1;
                vis[e] = currGrpNumber;
                ans = max(ans,groups[currGrpNumber]);
                grpEndNumber[currGrpNumber] = e;

            }
            if(vis.count(re)) {
                r = true;
                if(l) {
                    // left , element , right have to be merged
                    int leftGrpNumber = vis[e];
                    int rightGrpNumber = vis[re];
                    int lSize = groups[leftGrpNumber];
                    int rSize = groups[rightGrpNumber];

                    ans = max(ans,lSize + rSize);
                    grpEndNumber[leftGrpNumber] = grpEndNumber[rightGrpNumber];
                    vis[grpEndNumber[leftGrpNumber]] = leftGrpNumber;
                    groups[leftGrpNumber] = lSize + rSize;
                    grpEndNumber.erase(rightGrpNumber);
                    groups.erase(rightGrpNumber);
                } else {
                    int currGrpNumber = vis[re];
                    groups[currGrpNumber] += 1;
                    vis[e] = currGrpNumber;
                    ans = max(ans,groups[currGrpNumber]);
                }
            }
            if(!l && !r) {
                vis[e] = grpNumber;
                groups[grpNumber] = 1;
                grpEndNumber[grpNumber++] = e;
                ans = max(ans,1);
            }
        }
        return ans;
    }
};