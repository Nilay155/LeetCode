class Solution {
private:
    void mergeArrays(vector<int> &nums,int l,int r,int mid) {
        vector<int> left(mid - l + 1), right(r - mid);

        for(int k = 0 ; k < mid - l + 1 ; k++) {
            left[k] = nums[l + k];
        }
        for(int k = 0 ; k < r - mid ; k++) {
            right[k] = nums[mid + k + 1];
        }
        int k = l;
        int i = 0, n = left.size();
        int j = 0, m = right.size();

        while(i < n && j < m) {
            if(left[i] >= right[j]) 
                nums[k++] = right[j++];
            else
                nums[k++] = left[i++];
        }
        while(i < n) {
            nums[k++] = left[i++];
        }
        while(j < m) {
            nums[k++] = right[j++];
        }
        return ;
    }
    void mergeSort(vector<int> &nums,int l,int r) {
        if(l >= r)
            return ;
        
        int mid = l + (r - l) / 2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid + 1, r);
        mergeArrays(nums,l,r,mid);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size() - 1);
        return nums;
    }
};