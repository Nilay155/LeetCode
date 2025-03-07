class Seive{
public:
    vector<bool> seive;
    Seive(int size) {
        seive.resize(size+1,true);
    }

    void seiveOfErathosnes(int left,int right) {
        seive[0] = seive[1] = false;
        for(int i = 2 ; i*i <= right ; i++) {
            if(seive[i]) {
                for(int j = i*i ; j <= right ; j += i) {
                    seive[j] = false;
                }
            }
        }
    }
};
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // left <= num1 < num2 <= right .
        // Both num1 and num2 are prime numbers.
        // num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
        Seive primeNumbers(right);
        primeNumbers.seiveOfErathosnes(left,right);

        vector<bool> nums = primeNumbers.seive;
        vector<int> arr;
        for(int i = left ; i <= right ; i++) {
            if(nums[i]) arr.push_back(i);
        }
        int p1 = -1, p2 = -1;
        int mini = INT_MAX;
        int n = arr.size();
        for(int i = 0 ; i < n-1 ; i++) {
            int ele = arr[i];
            int val = arr[i+1];
            int temp = val - ele;
            if(temp < mini) {
                p1 = ele, p2 = val;
                mini = temp;
            }
        }
        return {p1,p2};
    }
};