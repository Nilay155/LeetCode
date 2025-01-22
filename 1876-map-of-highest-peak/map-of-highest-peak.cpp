class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
          queue<pair<int,int>>q;
          vector<vector<bool>>vis(isWater.size(),vector<bool>(isWater[0].size(),false));
          vector<vector<int>>ans(isWater.size(),vector<int>(isWater[0].size()));
          for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
          }
    vector<int>x={0,0,1,-1};
    vector<int>y={-1,1,0,0};

    int level=0;

          while(q.size()){
            int sz=q.size();
            for(int cnt=1;cnt<=sz;cnt++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                ans[i][j]=level;
                for(int p=0;p<4;p++){
                    int ni=x[p]+i;
                    int nj=y[p]+j;
                     if(ni>=0  && ni<isWater.size() && nj>=0 && nj<isWater[0].size()  && vis[ni][nj]==0){
                   vis[ni][nj]=1;
                   q.push({ni,nj});
                     }
                }
            }
            level++;
          }


          return ans;
    }
};