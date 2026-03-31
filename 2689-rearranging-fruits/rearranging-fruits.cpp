class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int n = b1.size();
        unordered_map<int,int> f1,f2;
        int mini = INT_MAX;
        
        for(int b : b1) mini = min(mini,b);
        for(int b : b2) mini = min(mini,b);

        for(int b : b1) f1[b] += 1;
        for(int b : b2) f2[b] += 1;

        vector<int> arr;
        for(auto [v,c] : f1) {
            int curr = c, rem = f2[v];
            if(curr > rem) {
                int diff = curr - rem;
                if(diff % 2 == 1) return -1;
                diff /= 2;
                while(diff--) arr.push_back(v);
            }
        }
        for(auto [v,c] : f2) {
            int curr = c, rem = f1[v];
            if(curr > rem) {
                int diff = curr - rem;
                if(diff % 2 == 1) return -1;
                diff /= 2;
                while(diff--) arr.push_back(v);
            }
        }
        int k = arr.size(); // s1.len == s2.len
        sort(arr.begin(),arr.end());
        long long ans = k/2 * (long long)mini * 2LL;
        long long sum = 0;
        for(int i = 0 ; i < k/2 ; i++) {
            long long q = k/2 - i - 1;
            sum += arr[i];
            ans = min(ans,sum + q * (long long) mini * 2);
        }
        return ans;
    }
};