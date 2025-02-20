class Solution {
private:
    string ans;
    bool solve(unordered_map<string,bool> &vis,int n,string temp) {
        if(n == 0) {
            if(vis.find(temp) != vis.end()) return false;
            
            ans = temp;
            return true;
        }

        if(solve(vis,n-1,temp+'1')) return true;
        if(solve(vis,n-1,temp+'0')) return true;
        return false;

    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_map<string,bool> vis;
        for(string str : nums) vis[str] = true;

        solve(vis,nums[0].size(),"");
        return ans;
    }
};