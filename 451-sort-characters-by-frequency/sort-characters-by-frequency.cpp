class Solution {
private:
    static bool cmp(const pair<int,char> &a,const pair<int,char> &b) {

        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> counts;
        for(char ch : s) counts[ch]++;

        vector<pair<int,char>> arr;
        for(auto [ch,cnt] : counts) arr.push_back({cnt,ch});

        sort(arr.begin(),arr.end(),cmp);
        string ans;

        for(int i = 0 ; i < arr.size() ; i++) {
            ans += string(arr[i].first,arr[i].second);
        }
        return ans;
    }
};