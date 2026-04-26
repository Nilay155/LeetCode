class Solution {
public:
    using ll = long long;

    ll totalSum = 0;
    ll ans = 0;
    const ll MOD = 1000000007;

    ll dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        ll sum = root->val + dfs(root->left) + dfs(root->right);
        return sum;   // no mod here
    }

    ll maxProductt(TreeNode* root) {
        if (root == nullptr) return 0;

        ll lSum = maxProductt(root->left);
        ll rSum = maxProductt(root->right);

        ll currSum = root->val + lSum + rSum;

        ans = max(ans, currSum * (totalSum - currSum)); // no mod here

        return currSum; // no mod here
    }

    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);
        maxProductt(root);

        return ans % MOD; // mod only at final answer
    }
};