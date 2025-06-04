class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // a + b + c == n
        // a + b == n - c

        long long ways = 0;
        for(int c = 0 ; c <= min(n,limit) ; c++) {
            if(n-c <= 2*limit) {
                // a + b
                int op1 = min(limit,n-c);
                int op2 = max(0,n-c-limit);
                ways += op1-op2+1;
                // cout << c << " : " << op1 << endl;
            }
        }
        return ways;
    }
};