class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());

        int i = 0;
        for(i = 0 ; i < n ; i++) {
            if(satisfaction[i] >= 0)
                break;
        }
        int k = 1, sum = 0, posSum = 0;
        for(int j = i ; j < n ; j++) {
            sum += k * satisfaction[j];
            posSum += satisfaction[j];
            k += 1;
        }

        int j = i - 1, ans = sum, negSum = 0, currSum = 0;
        k = 1;
        while(j >= 0) {
            int temp = satisfaction[j];
            currSum += temp;
            if(currSum + negSum + (sum + k * posSum) > ans) {
                ans = sum + k * posSum + negSum + currSum;
            }
            currSum += negSum;
            negSum += temp;
            k += 1, j -= 1;
        }
        return ans;

    }
};