class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        k = k%n;

        queue<int> q;
        for(int i = 0 ; i < n ; i++) q.push(i);
        int time = 0;
        while(!q.empty()) { 
            int index = q.front();
            q.pop();
            tickets[index]--;
            time += 1;
            if(tickets[k] == 0) return time;
            else if(tickets[index] > 0) q.push(index);
        }
        return -1;
    }
};