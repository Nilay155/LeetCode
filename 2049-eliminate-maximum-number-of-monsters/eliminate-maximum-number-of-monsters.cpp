class Solution {
private:
    int minutesTaken(int speed,int distance) {

        if(speed >= distance) 
            return 1;
        else
            return (distance % speed != 0 ? distance / speed  + 1 : distance / speed);
    }
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        for(int i = 0 ; i < n ; i++) {
            minHeap.push({minutesTaken(speed[i],dist[i])});
        }

        int currTime = 0, count = 0;
        while(!minHeap.empty()) {
            int top = minHeap.top(); minHeap.pop();
            if(currTime < top) {
                count += 1;
            } else {
                break;
            }
            currTime += 1;
        }
        return count;
    }
};