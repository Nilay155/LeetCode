class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int n = flowers.size();
        sort(flowers.begin(),flowers.end());
        map<int,int> flowerCount;

        for(int i = 0 ; i < n ; i++) {
            int s = flowers[i][0], e = flowers[i][1] + 1;
            flowerCount[s] += 1;
            flowerCount[e] -= 1;
        }

        map<int,int> mpp;
        int prefix = 0;
        for(auto [t,c] : flowerCount) {
            prefix += c;
            mpp[t] = prefix;
        }
        vector<int> ans;
        for(int i = 0 ; i < (int) people.size() ; i++) {
            auto it = mpp.lower_bound(people[i]);
            if(it == mpp.end()) ans.push_back(0);
            else {
                if(it->first == people[i]) ans.push_back(it -> second);
                else {
                    if (it != mpp.begin()) {
                        --it;
                        ans.push_back(it->second);
                    } else {
                        ans.push_back(0);
                    }
                }
            }
        }
        return ans;
    }
};