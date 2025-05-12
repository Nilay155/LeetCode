class Solution {
private:
    int mergeArrays(vector<int> &nums,int low,int mid,int high) {
        vector<int> leftHalf(mid-low+1);
        vector<int> rightHalf(high-mid);

        int k = 0, l = 0;
        for(int i = low ; i <= mid; i++) {
            leftHalf[k++] = nums[i];
        }
        for(int i = mid+1 ; i <= high ; i++) {
            rightHalf[l++] = nums[i];
        }

        int i = 0, j = 0, t = 0;
        vector<int> arr(high-low+1);
        long long int res = 0;

        while(i < k && j < l) {
            if(leftHalf[i] < rightHalf[j]) {
                arr[t++] = rightHalf[j++]; 
            } else {
                arr[t++] = leftHalf[i++];
            }
        }
        while(i < k) {
            arr[t++] = leftHalf[i++];
        } 
        while(j < l) {
            arr[t++] = rightHalf[j++];
        }

        i = 0, j = 0;
        while(i < k && j < l) {
            if(leftHalf[i] > (2LL*rightHalf[j])) {
                res += (l-j);
                i++;
            } else {
                j++;
            }
        }

        int z = low;
        for(int  f= 0 ; f < t ; f++) {
            nums[z++] = arr[f];
        }
        cout << res << endl;
        return res;
    }
    int divideConquer(vector<int> &nums,int low,int high) {
        if(low >= high) return 0;

        int mid = (low + high) >> 1;
        int left = divideConquer(nums,low,mid);
        int right = divideConquer(nums,mid+1,high);
        int merge = mergeArrays(nums,low,mid,high);

        return (left + right + merge);
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans = divideConquer(nums,0,nums.size()-1);
        // for(int num : nums) cout << num << " : ";
        return ans;
    }
};