class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> vis;
        vis[n] = true;
        while(n != 1) {
            int k = n;
            int newNumber = 0;
            while(k) {
                int digit = k % 10;
                newNumber += (digit * digit);
                k /= 10;
            }
            if(vis.find(newNumber) != vis.end()) return false;
            else {
                n = newNumber;
                vis[n] = true;
            }
        }
        return true;
    }
};