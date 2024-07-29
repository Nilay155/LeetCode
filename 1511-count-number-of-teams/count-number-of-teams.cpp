class Solution {
public:
    int numTeams(vector<int>& rating) {

        int n = rating.size();
        int res = 0;

        for(int i = 0 ; i < n ; i++) {
            int leftMax = 0;
            int leftMin = 0;

            for(int j = 0 ; j < i ; j++) {
                if(rating[i] > rating[j]) leftMax++;
                if(rating[i] < rating[j]) leftMin++;
            }

            int rightMax = 0;
            int rightMin = 0;

            for(int k = i+1 ; k < n ; k++) {
                if(rating[i] > rating[k]) rightMax++;
                if(rating[i] < rating[k]) rightMin++;
            }

            res += (leftMin*rightMax) + (leftMax*rightMin);
        }
        return res;
    }

};