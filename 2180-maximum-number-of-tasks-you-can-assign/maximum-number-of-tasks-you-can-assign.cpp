class Solution {
private:
    bool isPossible(vector<int> tasks,vector<int> &workers,int pills,int strength,int mid) {

        multiset<int> mst(workers.begin(),workers.end());

        for(int i = mid-1; i >= 0 ; i--) {

            auto it = prev(mst.end());
            if(*it >= tasks[i]) {
                mst.erase(it);
            } else {
                if(pills <= 0) return false;
                auto it = mst.lower_bound(tasks[i]-strength);
                if(it == mst.end()) return false;
                pills--;
                mst.erase(it); 
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());

        int s = 0, e = min(n,m);

        while(s <= e) {
            int mid = (s + e) >> 1;

            if(isPossible(tasks,workers,pills,strength,mid)) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        return e;
    }
};