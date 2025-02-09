class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string,bool> mpp;
    void dfs(int src,vector<bool> &vis,unordered_map<string,vector<int>> &mergedAccounts,vector<string> &temp,vector<vector<string>> &accounts) {

        vis[src] = true;

        for(int i = 1 ; i < accounts[src].size() ; i++) {
            for(int node : mergedAccounts[accounts[src][i]]) {
                if(!vis[node]) {
                    dfs(node,vis,mergedAccounts,temp,accounts);
                }
            }
            if(!mpp.count(accounts[src][i])) {
                temp.push_back(accounts[src][i]);
                mpp[accounts[src][i]]=true;
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        // the first element accounts[i][0] is a name, 
        // and the rest of the elements are emails representing emails of the account.
        // merge these accounts

        unordered_map<string,vector<int>> mergedAccounts;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 1 ; j < accounts[i].size() ; j++) {

                mergedAccounts[accounts[i][j]].push_back(i);
            }
        }
        vector<bool> vis(n,false);

        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                vector<string> temp;
                dfs(i,vis,mergedAccounts,temp,accounts);
                sort(temp.begin(),temp.end());
                temp.insert(temp.begin(),accounts[i][0]);
                ans.push_back(temp);

            }
        }
        return ans;
    }
};