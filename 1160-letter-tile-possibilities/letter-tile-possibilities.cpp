class Solution {
private:
    int f(int n,vector<int> &count) {
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++) {

            if(count[i]) {
                count[i] -= 1;
                ans += 1 + f(n - 1, count);
                count[i] += 1;
            }
        }
        return ans;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> count(26,0);
        for(char ch : tiles) count[ch - 'A'] += 1;

        int n = tiles.size();
        return f(n,count);
    }
};