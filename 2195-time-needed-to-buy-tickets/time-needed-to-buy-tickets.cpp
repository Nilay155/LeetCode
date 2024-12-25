class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        k = k%n;

        int time = 0;
        int temp = 0;
        for(int i = 0 ; i < n ; i++) {
            if(tickets[i] < tickets[k]) {
                time += tickets[i];
                temp = max(temp,tickets[i]);
            } else if(tickets[i] >= tickets[k]) {
                if(i <= k) time += tickets[k];
                else time += tickets[k]-1;
            }
        }
        return time;

    }
};