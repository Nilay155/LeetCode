typedef long long ll;
class Solution {
public:
Solution() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
}
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

   priority_queue<ll,vector<ll>, greater<ll>> pq(nums.begin(), nums.end());

        int res = 0;

        while(pq.size() > 1) {
            ll num1 = pq.top(); pq.pop();
            ll num2 = pq.top(); pq.pop();

            if(num1 < k) {
                ll temp = min(num1,num2) * 2LL + max(num1,num2);
                res += 1;
                pq.push(temp);
            }

        }
        return res;
    }
};