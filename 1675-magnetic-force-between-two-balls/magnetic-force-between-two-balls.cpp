class Solution {
private:
    bool check(vector<int> &position,int mid,int m) {

        int n = position.size(), count = 1, last = position[0];

        for(int i = 1 ; i < n ; i++) {
            int curr = position[i];
            if(curr - last >= mid) {
                last = curr;
                count += 1;
            }
        }
        return count >= m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int l = 1, r = position[n - 1] - position[0];

        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            if(check(position,mid,m)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};