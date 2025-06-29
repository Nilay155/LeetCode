class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();
        unordered_map<int,int> nextGreater;
        stack<int> st;

        for(int i = m-1 ; i >= 0 ; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) nextGreater[nums2[i]] = -1;
            else nextGreater[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        vector<int> ans(n,-1);
        for(int i = 0 ; i < n ; i++) {
            if(nextGreater.find(nums1[i]) != nextGreater.end()) {
                ans[i] = nextGreater[nums1[i]];
            }
        }
        return ans;
    }
};