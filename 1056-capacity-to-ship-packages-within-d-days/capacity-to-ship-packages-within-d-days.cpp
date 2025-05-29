class Solution {
private:
    int sum(vector<int> &weights) {
        int totalSum = 0;
        for(int weight : weights) totalSum += weight;
        return totalSum;
    }
private:
    bool isPossible(vector<int> &weights,int mid,int days) {
        int count = 0, sum = 0;

        for(int weight : weights) {
            if(weight > mid) return false;
            if(sum + weight > mid) {
                count += 1;
                sum = weight;
            } else {
                sum += weight;
            }
        }
        count += 1;
        return count <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int s = 1, e = sum(weights);

        while(s <= e) {
            int mid = (s + e) >> 1;
            if(isPossible(weights,mid,days)) {
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return s;
    }
};