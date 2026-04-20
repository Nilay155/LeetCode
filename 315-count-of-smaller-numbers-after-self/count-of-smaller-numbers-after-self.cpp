class Solution {
private:
    vector<int> ans;

    void merge(vector<pair<int,int>>& nums, int l, int mid, int r, vector<pair<int,int>>& temp) {
        int i = l, j = mid + 1, k = l;

        while (i <= mid && j <= r) {
            if (nums[i].first <= nums[j].first) {
                ans[nums[i].second] += (j - (mid + 1));
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            ans[nums[i].second] += (j - (mid + 1));
            temp[k++] = nums[i++];
        }

        while (j <= r) {
            temp[k++] = nums[j++];
        }

        for (int x = l; x <= r; x++) nums[x] = temp[x];
    }

    void divide(vector<pair<int,int>>& nums, int l, int r, vector<pair<int,int>>& temp) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        divide(nums, l, mid, temp);
        divide(nums, mid + 1, r, temp);
        merge(nums, l, mid, r, temp);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {nums[i], i};

        ans.assign(n, 0);
        vector<pair<int,int>> temp(n);

        divide(arr, 0, n - 1, temp);
        return ans;
    }
};