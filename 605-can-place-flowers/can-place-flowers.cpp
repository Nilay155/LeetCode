class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int m = fb.size();

        int i = 0;
        while(i < m) {

            if(fb[i] == 0) {
                bool left  = (i-1 >= 0 ? fb[i-1] != 1 : true);
                bool right = (i+1 < m ? fb[i+1] != 1 : true);
                if(left && right) {
                    fb[i] = 1;
                    n -= 1;
                }
            }
            i += 1;
        }
        return n <= 0;
    }
};