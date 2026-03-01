class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // atmost k projects can be done
        int n = profits.size();
        int count = 0;
        priority_queue<pair<int,int>> ds1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> ds2;
        for(int i = 0 ; i < n ; i++) {
            if(capital[i] <= w) 
                ds1.push({profits[i],capital[i]});
            else
                ds2.push({capital[i],profits[i]});
        }

        while(count < k) {
            
            if(!ds1.empty()) {
                w += ds1.top().first;
                ds1.pop();
            } else {
                break;
            }
            while(!ds2.empty() && ds2.top().first <= w) {
                auto [c,p] = ds2.top();
                ds2.pop();
                ds1.push({p,c});
            }
            count += 1;
        }
        return w;
    }
};