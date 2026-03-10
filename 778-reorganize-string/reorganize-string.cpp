class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        vector<int> count(26,0);
        for(char ch : s) count[ch - 'a'] += 1;

        priority_queue<pair<int,char>> pq;
        for(int i = 0 ; i < 26 ; i++) {
            if(count[i])
                pq.push({count[i],'a' + i});
        }

        string ans;
        while(!pq.empty()) {
            auto [c1,ch1] = pq.top(); pq.pop();
            auto [c2,ch2] = make_pair(0,' ');
            if(!pq.empty()) {
               c2 = pq.top().first;
               ch2 = pq.top().second; pq.pop();
            }

            if(c2 == 0 && c1 > 1) return "";
            ans.append(1,ch1);
            if(c2 > 0)
                ans.append(1,ch2);

            c1--,c2--;

            if(c1 > 0) pq.push({c1,ch1});
            if(c2 > 0) pq.push({c2,ch2});
        }
        return ans;
    }
};