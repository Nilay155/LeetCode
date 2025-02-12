class SegmentTree{
    public:
        vector<int> seg;
        SegmentTree(int n) {
            seg.resize(4*n,1e9);
        }
        void build(int idx,int low,int high,vector<int> &arr) {
            if(low == high) {
                seg[idx] = arr[low];
                return ;
            }
            int mid = (low + high) >> 1;
            build(2*idx+1,low,mid,arr);
            build(2*idx+2,mid+1,high,arr);
            seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
        }

        int query(int idx,int low,int high,int left,int right) {

            // No-Overlap
            if(high < left || low > right) return INT_MAX;

            // Complete Overlap
            if(low >= left && high <= right) return seg[idx];

            // Partial Overlap
            int mid = (low + high) >> 1;
            int l =  query(2*idx+1,low,mid,left,right);
            int r = query(2*idx+2,mid+1,high,left,right);
            return min(l,r);
        }
        void update(int idx,int l,int r,int i,int val) {

            if(l == r) {
                seg[idx] = val;
                return ; 
            }

            int mid = (l + r) >> 1;
            if(i <= mid) update(2*idx+1,l,mid,i,val);
            else update(2*idx+2,mid+1,r,i,val);

            seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
        }
};
class Solution {
private:
    static bool cmp(vector<int> &a,vector<int> &b) {
        if(a[1] < b[1]) return true;
        else return false;
    }
public:
    int minTaps(int n, vector<int>& ranges) {
        int m = n+1;
        // minimum number of taps needed to water gardern

        vector<vector<int>> nums;

        for(int i = 0 ; i < m ; i++) {
            int leftRange = i-ranges[i];
            int rightRange = i+ranges[i];
            // [leftRange,rightRange]

            if(leftRange <= 0) leftRange = 0;
            if(rightRange >= n) rightRange = n;
            nums.push_back({leftRange,rightRange});
        }
        sort(nums.begin(),nums.end(),cmp);

        vector<int> dp(m,1e9);
        dp[0] = 0;
        
        SegmentTree arr(m);
        arr.build(0,0,n,dp);

        for(int i = 0 ; i < m ; i++) {

            int start = nums[i][0];
            int end = nums[i][1];
            if(start == end) continue;

            // get min from start to end-1.
            int mini = arr.query(0,0,n,start,end-1);
            dp[end] = min(dp[end],1 + mini);

            arr.update(0,0,n,end,dp[end]);

        }
        if(dp[n] != 1e9) return dp[n];
        return -1;
        
    }
};