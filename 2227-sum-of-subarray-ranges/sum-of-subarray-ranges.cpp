class Solution {
private:
     long long maxi(vector<int> &nums) {
        int n = nums.size();

        vector<int> count(n,1);

        stack<int> st;
        st.push(-1);

        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && st.top() != -1 && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            int num = i - st.top();
            count[i] *= num;
            st.push(i);
        }
        st = stack<int>();
        st.push(n);
        for(int i = n-1 ; i >= 0 ; i--) {
            while(!st.empty() && st.top() != n && nums[st.top()] < nums[i]) {
                st.pop();
            }
            int num = st.top()-i;
            count[i] *= num;
            st.push(i);
        }

        long long res = 0;
        for(int i = 0 ; i < n ; i++) {
            res += (1LL * count[i] * nums[i]);
        }
        return res;
    }
private:
    long long mini(vector<int> &nums) {
        int n = nums.size();

        vector<int> count(n,1);

        stack<int> st;
        st.push(-1);

        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && st.top() != -1 && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            int num = i - st.top();
            count[i] *= num;
            st.push(i);
        }
        st = stack<int>();
        st.push(n);
        for(int i = n-1 ; i >= 0 ; i--) {
            while(!st.empty() && st.top() != n && nums[st.top()] > nums[i]) {
                st.pop();
            }
            int num = st.top()-i;
            count[i] *= num;
            st.push(i);
        }

        long long res = 0;
        for(int i = 0 ; i < n ; i++) {
            res += (1LL * count[i] * nums[i]);
        }
        return res;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return maxi(nums) - mini(nums);
    }
};