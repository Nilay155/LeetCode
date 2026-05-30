class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int maximumArea = 0;
        int i = 0, j = n-1;

        while(i < j) {
            int b = j - i;
            int l = min(arr[i],arr[j]);
            maximumArea = max(maximumArea,l * b);

            if(arr[i] > arr[j]) j--;
            else i++;
        }
        return maximumArea;
    }
};