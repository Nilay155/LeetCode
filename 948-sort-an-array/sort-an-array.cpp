class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int num : nums) {
            pq.push(num);
        }

        vector<int> res;

        while(!pq.empty()) {
            int num = pq.top();
            pq.pop();

            res.push_back(num);
        }
        return res;
    }
};