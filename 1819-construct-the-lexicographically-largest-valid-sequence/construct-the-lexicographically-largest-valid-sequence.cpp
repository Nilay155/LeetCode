
class Solution {
private:
    vector<int> ans;
    void check(vector<int> &temp) {
        if(ans.empty()) {
            ans = temp;
            return ;
        }

        for(int i = 0 ; i < ans.size() ; i++) {
            if(ans[i] == temp[i]) continue;
            if(ans[i] < temp[i]) ans = temp;
            else break;
        }

    }
    bool solve(int n,vector<int> &temp,vector<bool> &count,int index) {
        while (index < temp.size() && temp[index] != 0) {
            index++;
        }
        if(temp.size() == index) {
            ans = temp;
            return true;
        }

        for(int i = n ; i >= 1 ; i--) {
           if(count[i]) continue;

           if(i == 1) {
                temp[index] = 1;
                count[1] = true;
                if(solve(n,temp,count,index+1)) return true;
                temp[index]=0;
                count[1] = false;
           } else if(index + i < temp.size() && temp[i+index] == 0){
                temp[index] = i;
                temp[index + i] = i;
                count[i] = true;
                if(solve(n,temp,count,index+1)) return true;
                temp[index] = 0;
                temp[index + i] = 0;
                count[i] = false;
           }
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        // ans.size() == 2*n-1
        vector<int> temp(2*n-1,0);
        vector<bool> count(n+1,0);
        solve(n,temp,count,0);
        return ans;
    }
};