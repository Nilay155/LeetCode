class Solution {
public:
    int func(int n,int turn) {
        
        int ans = 1;
        for(int i = 1 ; i < n ; i++) {
            if(n%i == 0) {
                // A player can play
                ans &= func(n-i,(turn == 1) ? 2 : 1);
            }
        }
        return ans;
    }
    bool divisorGame(int n) {
        // 0 < x < n && n % x == 0
        // replace n -> n-x
        // player loses if they cannot make a move
        // return true if alice wins else false
        // both are playing optimally

        // return func(n,1);
        // return 1;
        if(n&1) return 0;
        else return 1;
    }
};