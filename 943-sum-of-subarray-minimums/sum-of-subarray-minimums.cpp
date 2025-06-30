class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;

        vector<int> count(n,1);

        stack<int> st;
        st.push(-1);
        for(int i = 0 ; i < n ; i++) {

            while(!st.empty() && st.top() != -1 && arr[st.top()] > arr[i]) {
                st.pop();
            }
            
            int num = i - st.top();
            count[i] *= num;
            st.push(i);
        }
        st = stack<int>();
        st.push(n);

        for(int i = n-1 ; i >= 0 ; i--) {
            while(!st.empty() && st.top() != n && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            int num = st.top()-i;
            count[i] *= num;
            st.push(i);
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            long long temp = (1LL*count[i]*arr[i]) % MOD;
            ans = (ans + temp) % MOD;
        }
        return ans;
    }
};