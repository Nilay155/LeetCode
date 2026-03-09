class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        priority_queue<tuple<double,int,int>,vector<tuple<double,int,int>>,greater<tuple<double,int,int>>> pq;

        for(int i = 0 ; i < n ; i++) {
            if(i < n-1) 
                pq.push({(double)arr[i]/(double)arr[n-1],i,n-1});
        }
        int u = -1, v = -1;
        while(k--) {
            auto [fraction,i,j] = pq.top(); pq.pop();
            u = i, v = j;
            if(i < j-1) 
                pq.push({(double)arr[i]/(double)arr[j-1],i,j-1});
        }
        return {arr[u],arr[v]};
    }
};