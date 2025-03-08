class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int black = 0, white = 0;
        int i = 0, j = 0;
        int mini = n;
        while(j < n) {
            if(blocks[j] == 'W') white += 1;
            else black += 1;

            if(j-i >= k) {
                if(blocks[i] == 'W') white -= 1;
                else black -= 1;
                i++;
            }
            if(white + black == k) {
                mini = min(mini,white);
            }
            j++;
        }
        return mini;
    }
};