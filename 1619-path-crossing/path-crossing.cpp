class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.length();
        set<pair<int,int>> st;  
        int u = 0, v = 0;
        st.insert({u,v});
        
        for(int i = 0 ; i < n ; i++) {
            if(path[i] == 'N') v += 1;
            else if(path[i] == 'S') v -= 1;
            else if(path[i] == 'E') u += 1;
            else u -= 1;

            if(st.count({u,v})) return true;
            st.insert({u,v});
        }
        return false;
    }
};