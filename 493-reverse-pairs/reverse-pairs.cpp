class Solution {
private:
    int count(vector<int> &nums,int l,int mid,int r) {
        
        vector<int> leftHalf(mid - l + 1), rightHalf(r - mid);
        for(int k = 0 ; k < mid - l + 1 ; k++) leftHalf[k] = nums[k + l];
        for(int k = 0 ; k < r - mid ; k++) rightHalf[k] = nums[mid + k + 1];

        int pairs = 0;
        int i = 0, j = 0,n = mid - l + 1, m = r - mid;
        while(i < n) {

            while(j < m && (1LL * leftHalf[i] > 2LL * rightHalf[j])) j += 1;
            
            pairs += j;
            i += 1;
        } 
        
        int k = l;
        i = 0, j = 0;
        while(i < n && j < m) {
            if(leftHalf[i] > rightHalf[j]) {
                nums[k++] = rightHalf[j++];
            } else {
                nums[k++] = leftHalf[i++];
            }
        }
        while(i < n) nums[k++] = leftHalf[i++];
        while(j < m) nums[k++] = rightHalf[j++];

        return pairs;
    }
    int countPairs(vector<int> &nums,int l,int r) {
        
        if(l >= r) 
            return 0;
        
        int mid = l + (r - l) / 2;
        int leftHalf = countPairs(nums,l,mid);
        int rightHalf = countPairs(nums,mid + 1,r);
        int countCurrentPairs = count(nums,l,mid,r);

        return (countCurrentPairs + leftHalf + rightHalf);
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans = countPairs(nums,0,nums.size() - 1);
        for(int n : nums) cout << n << " ";
        return ans;
    }
};