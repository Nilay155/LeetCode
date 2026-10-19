class Solution {
private:
    long long dp[11][2];
    bool vis[11][2];

    long long f(vector<int>& numbers, int i, string& high, bool flag) {
        int n = high.size();

        if (i == n)
            return 1;

        if (vis[i][flag])
            return dp[i][flag];

        vis[i][flag] = true;

        long long ans = 0;
        int limit = flag ? high[i] - '0' : 9;

        for (int x : numbers) {
            if (i == 0 && x == 0)
                continue;

            if (x > limit)
                continue;

            bool newFlag = flag && (x == high[i] - '0');

            ans += f(numbers, i + 1, high, newFlag);
        }

        return dp[i][flag] = ans;
    }

    long long countUpTo(vector<int>& numbers, string high) {
        int n = high.size();
        long long ans = 0;

        // Count numbers with fewer than n digits
        int first = 0, total = numbers.size();

        for (int x : numbers)
            if (x != 0)
                first++;

        for (int len = 1; len < n; len++) {
            long long ways = first;

            for (int j = 1; j < len; j++)
                ways *= total;

            ans += ways;
        }

        // Count numbers with exactly n digits
        memset(vis, false, sizeof(vis));
        ans += f(numbers, 0, high, true);

        return ans;
    }

public:
    int atMostNGivenDigitSet(vector<string>& digits, int high) {
        vector<int> numbers;

        for (auto& d : digits)
            numbers.push_back(stoi(d));

        sort(numbers.begin(), numbers.end());

        string s = to_string(high);

        return countUpTo(numbers, s);
    }
};