class Solution {
public:
    vector<bool> arr;
    bool isPossible(vector<int> &banned,int n,int maxSum,int k) {

        int sum = 0;
        int count = 0;
        int flag = 0;

        for(int i = 0 ; i < n ; i++) {
            if(!arr[i]) {
                count += 1;
                sum += (i+1);
            }
            if(sum > maxSum) {
                flag = 1;
                break;
            }
        }

        if(flag) count--;
        // cout << k << " : " << count << endl;
        return count >= k;

    }
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m = banned.size();
        arr = vector<bool>(n,false);
        for(int i = 0 ; i < m ; i++) {
            if(banned[i] <= n) {
                arr[banned[i]-1] = true;
            }
        }

        int start = 0;
        int end = n;

        while(start <= end) {
            int mid = (start + end) >> 1;
            if(isPossible(banned,n,maxSum,mid)) {
                start = mid + 1;
            } else {    
                end = mid - 1;
            }
        }
        return end;
    }
};