class Solution {
private:
    vector<int> computeLargest(vector<int> &nums,int k) {
        stack<int> st;
        int n = nums.size();
        int drops = n - k;
        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && st.top() < nums[i] && drops) {
                st.pop();
                drops -= 1;
            }
            st.push(nums[i]);
        }
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return vector<int>(res.begin(),res.begin() + k);
    }
    vector<int> makeLargestNumber(vector<int> &a,vector<int> &b) {

        int i = 0, n = a.size();
        int j = 0, m = b.size();
        vector<int> ans;
        while(i < n && j < m) {
            if(a[i] > b[j]) {
                ans.push_back(a[i]);
                i += 1;
            } else if(b[j] > a[i]) {
                ans.push_back(b[j]);
                j += 1;
            } else {
                int l = i, r = j;
                while(l+1 < n && r+1 < m && a[l+1] == b[r+1]) {
                    l += 1, r += 1;
                }
                if(l+1 < n && r+1 < m) {
                    if(a[l+1] > b[r+1]) ans.push_back(a[i++]);
                    else ans.push_back(b[j++]);
                } else {
                    if(l+1 == n) ans.push_back(b[j++]);
                    else ans.push_back(a[i++]);
                }
            }
        }
        while(i < n) {
            ans.push_back(a[i]);
            i += 1;
        }
        while(j < m) {
            ans.push_back(b[j]);
            j += 1;
        }
        return ans;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans;
        for(int i = 0 ; i <= k ; i++) {
            int k1 = i, k2 = k - i;
            if(k1 > n || k2 > m) continue;

            vector<int> a1 = computeLargest(nums1,k1);
            vector<int> a2 = computeLargest(nums2,k2);

            vector<int> res = makeLargestNumber(a1,a2);
            
            if(res > ans)
                ans = res;
        }
        return ans;
    }
};