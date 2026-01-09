class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        unordered_map<string,vector<int>> groups;
        for(int i = 0 ; i < n ; i++) {
            string s = strs[i];
            sort(s.begin(),s.end());
            groups[s].push_back(i);
        }
        vector<vector<string>> ans;

        for(auto [s,arr] : groups) {
            vector<string> temp;
            for(int i = 0 ; i < arr.size() ; i++) {
                temp.push_back(strs[arr[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};