class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        unordered_map<int,unordered_map<int,double>> multipliers;
        if(poured == 0)
            return 0.0;
        
        query_row++, query_glass++;

        multipliers[1][1] = (double) (poured);
        for(int i = 2; i <= 100; i++) {

            // First Glass
            if(multipliers[i - 1][1] - 1.0 > 0.0) {
                multipliers[i][1] += (multipliers[i - 1][1] - 1.0) / 2.0;
            }
            // Last Glass
            if(multipliers[i - 1][i - 1] - 1.0 > 0.0) {
                multipliers[i][i] += (multipliers[i - 1][i - 1] - 1.0) / 2.0;
            }
            // Middle Glasses
            for(int j = 2; j < i; j++) {
                if(multipliers[i - 1][j - 1] - 1.0 > 0.0) {
                    multipliers[i][j] +=
                        (multipliers[i - 1][j - 1] - 1.0) / 2.0;
                }

                if(multipliers[i - 1][j] - 1.0 > 0.0) {
                    multipliers[i][j] +=
                        (multipliers[i - 1][j] - 1.0) / 2.0;
                }
            }
        }

        return multipliers[query_row][query_glass] >= 1.0 ? 1.0 : 
               multipliers[query_row][query_glass];
    }
};