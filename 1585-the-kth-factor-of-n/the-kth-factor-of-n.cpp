class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> front,back;
        for(int i = 1 ; i*i <= n ; i++) {
            if(n%i == 0) {
                int f1 = i, f2 = n/i;
                if(f1 != f2) {
                    front.push_back(f1);
                    back.push_back(f2);
                } else {
                    front.push_back(f1);
                }
            }
        }
        int ans = -1;
        int kth = 0;
        if(front.size() >= k) return front[k-1];
        
        kth = front.size();
        for(int i = back.size()-1 ; i >= 0 ; i--) {
            if(++kth == k) {
                ans = back[i];
                break;
            }
        }
        return ans;
    }
};