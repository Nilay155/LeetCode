class Solution {
private:
    bool citationCheck(vector<int> &cc,int k) {

        int count = 0;
        for(int c : cc) {
            if(c >= k) count += 1;
        }
        return count >= k;
    }
public:
    int hIndex(vector<int>& c) {
        
        int l = 0, r = *max_element(c.begin(),c.end());
        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(citationCheck(c,mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};