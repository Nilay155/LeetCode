class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string,bool> map;
        for(auto s : nums) map[s] = true;

        for(int i = 0 ; i < (1 << n) ; i++) { // 2^n combinations
            string temp;
            for(int j = n-1 ; j >= 0 ; j--) {

                if(i & (1 << j)) {
                    temp.push_back('1');
                } else {
                    temp.push_back('0');
                }
            }
            if(map.find(temp) == map.end()) return temp;
        }
        return "";
    }
};