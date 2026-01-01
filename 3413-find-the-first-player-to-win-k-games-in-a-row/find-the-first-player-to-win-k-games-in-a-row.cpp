class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        k = min(k,n);
        int wins = 0;
        int winner = 0;

        for(int i = 1 ; i < n ; i++) {

            if(skills[winner] > skills[i]) {
                wins += 1;
            } else {
                wins = 1;
                winner = i;
            }
            if(wins >= k) return winner;
        }
        return winner;
    }
};