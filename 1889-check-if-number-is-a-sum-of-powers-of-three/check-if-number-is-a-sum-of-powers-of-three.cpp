class Solution {
private:
    bool solve(int n,long long target,int j) {
        if(n == target) return 1;
        if(n < target) return 0;

        for(int i = j ; i <= 15 ; i++) {
            long long  temp = pow(3,i);
            if(target + temp <= n)
                if(solve(n,target + temp,i+1)) return 1;
        }
        return 0;
    }
public:
    bool checkPowersOfThree(int n) {
        return solve(n,0,0);
    }
};