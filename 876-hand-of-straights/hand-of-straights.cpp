class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;

        int need = n/groupSize;
        map<int,int> mpp;
        for(int h : hand) mpp[h] += 1;

        while(need--) {

            int cnt = 0;
            int prev = -1;
            for(auto it = mpp.begin() ; it != mpp.end() && cnt < groupSize ; it++,cnt++) {
                if(prev == -1) {
                    prev = it -> first;
                    mpp[prev] -= 1;
                    if(mpp[prev] == 0) mpp.erase(prev);
                } else {
                    if(it -> first != prev + 1) {
                        return false;
                    } else {
                        prev = it -> first;
                        mpp[prev] -= 1;
                        if(mpp[prev] == 0) mpp.erase(prev);
                    }
                }
            }
        }
        return mpp.size() == 0;
    }
};