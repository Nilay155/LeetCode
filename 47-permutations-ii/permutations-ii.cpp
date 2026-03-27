class Solution {
private:
    vector<int> arr;
    vector<vector<int>> ans;

    void f(vector<int> &freq,int count) {
        if(count == 0) {
            ans.push_back(arr);
            return ;
        }

        for(int k = 0 ; k <= 20 ; k++) {

            if(freq[k]) {
                arr.push_back(k - 10);
                freq[k] -= 1;
                f(freq,count - 1);
                freq[k] += 1;
                arr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> freq(21,0);
        for(int f : nums) freq[f + 10] += 1;
        int n = nums.size();
        f(freq,n);
        return ans;
    }
};