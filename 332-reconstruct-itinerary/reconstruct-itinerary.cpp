class Solution {
private: 
public:
    vector<string> path;
    void dfs(unordered_map<string,vector<string>> &adjList,string str) {

        while(!adjList[str].empty()) {
            string curr = adjList[str].back();
            adjList[str].pop_back();
            dfs(adjList,curr);
        }
        path.push_back(str);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();

        unordered_map<string,vector<string>> adjList;

        for(int i = 0 ; i < n ; i++) {
            string departure = tickets[i][0];
            string arrival = tickets[i][1];

            adjList[departure].push_back(arrival);
        }
        
        for(auto& it : adjList) {
            sort(it.second.rbegin(),it.second.rend());
        }
        dfs(adjList,"JFK");
        reverse(path.begin(),path.end());
        return path;
    }
};