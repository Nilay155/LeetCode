#define ll long long int 
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ll ans = 0;
        multimap<ll,ll> mpp;

        int i = 0, j = 0;
        int n = nums.size();

        while(j < n) {
            mpp.insert({nums[j],j});
            ll minElement = mpp.begin()->first;
            ll maxElement = mpp.rbegin()->first;
            // cout << minElement << "  " << maxElement << endl;
            while(i < j && (maxElement-minElement > 2)) {
                auto it = mpp.find(nums[i]);  // Iterator to the first element with key 3
                if (it != mpp.end()) {
                    // Erase only the first occurrence of key 3
                    mpp.erase(it);
                }
                minElement = mpp.begin()->first;
                maxElement = mpp.rbegin()->first;
                
                // cout << minElement << "  " << maxElement << endl;
                cout << endl;
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};