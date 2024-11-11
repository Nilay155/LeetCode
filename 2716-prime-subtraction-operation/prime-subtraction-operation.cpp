class Solution {
public:
    bool isPrime(int n) {

        for(int i = 2 ; i*i <= n ; i++) {
            if(n%i == 0) return 0;
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        int prev = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--) {
            int curr = nums[i];
           
            if(curr >= prev) {
                // Reduce this number
                // curr element se smallest prime factor which is satisfying
                int range = curr-1;
                int flag = 0;
                for(int k = 2 ; k <= range ; k++) {
                    if(isPrime(k)) {
                        if(curr-k < prev) {
                            curr -= k;
                            flag = 1;
                            break;
                        }
                    }
                }
                if(!flag) return 0;
            }
            prev = curr; 
        }
        return 1;
    }
};