class Solution {
public:

    long long dp[101][101][101];

    long long solve(vector<int> &robot,vector<int> &distance,vector<int> &limit,int i,int j,int cnt,int &n,int &m) {
        if(i >= n) return 0; // Repairing Done For All Robots
        if(j >= m) return LLONG_MAX;
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];
      
        long long op1 = LLONG_MAX;
        long long op2 = 0 + solve(robot,distance,limit,i,j+1,0,n,m);

        if(cnt < limit[j]) {
            long long mini = abs(distance[j]-robot[i]);
            long long rec = solve(robot,distance,limit,i+1,j,cnt+1,n,m);
            if(rec != LLONG_MAX)
                op1 = min(op1, mini + rec);
        }
        return dp[i][j][cnt] = min(op1,op2);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
 
        int n = robot.size();
        int m = factory.size();

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> limit,distance;
        for(int i = 0 ; i < m ; i++) {
            limit.push_back(factory[i][1]);
            distance.push_back(factory[i][0]); 
        }
        memset(dp,-1,sizeof(dp));
        return solve(robot,distance,limit,0,0,0,n,m);
    }
};