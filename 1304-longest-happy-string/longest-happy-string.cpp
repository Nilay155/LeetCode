class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a)
            pq.push({a,'a'});
        if(b)
            pq.push({b,'b'});
        if(c)
            pq.push({c,'c'});

        string ans;
        while(pq.size() > 1) {
            auto [f,ch1] = pq.top(); pq.pop();
            auto [s,ch2] = pq.top(); pq.pop();
            if(f == 0 || s == 0) break;
            
            if(f > s) {
                ans.append(2,ch1);
                ans.append(1,ch2);

                if(f - 2 > 0) pq.push({f - 2,ch1});
                if(s - 1 > 0) pq.push({s - 1,ch2});
            } else {
                ans.append(1,ch1);
                ans.append(1,ch2);

                if(f - 1 > 0) pq.push({f - 1,ch1});
                if(s - 1 > 0) pq.push({s - 1,ch2});
            }
        }
        if(!pq.empty()) {
            if(ans.empty()) 
                ans.append(min(2,pq.top().first),pq.top().second);
            else if(ans.back() != pq.top().second) 
                ans.append(min(2,pq.top().first),pq.top().second);
        }
        return ans;
    }
};