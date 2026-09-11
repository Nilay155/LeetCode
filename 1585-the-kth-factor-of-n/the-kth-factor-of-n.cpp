class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;

        for(int s = 1 ; s <= sqrt(n) ; s++) {
            if(n % s == 0) {
                factors.push_back(s);
                int t = n / s;
                if(n % t == 0 && s != t) 
                    factors.push_back(t);
            }
        }
        sort(factors.begin(),factors.end());
        if(factors.size() < k)
            return -1;
        return factors[k - 1];
    }
};