class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int min1 = INT_MAX, min2 = INT_MAX;

        for(int price : prices) {
            if(price < min1) {
                min2 = min1;
                min1 = price;
            } else if(price < min2) {
                min2 = price;
            }
        }

        if(min1 + min2 > money) return money;
        else return money - min1 - min2;
    }
};