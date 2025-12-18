class Solution {
public:
    // We want dp[i] to represent the maximum profit we can achieve
    // on or before that day
    // ex:
    // dp[0] = -7
    // dp[1] = -1
    // dp[2] = 4 because -1+5 = 4
    // dp[3] = 4 because -1+3 = 2 < 4
    int maxProfit(vector<int>& prices) {
        int dp[100001], pr[100001];
        
        pr[0] = -prices[0];
        dp[0] = -0x3f3f3f3f;
        int n = prices.size();
        
        for(int i = 1; i < n; i++) {
            dp[i] = max(pr[i-1] + prices[i], dp[i-1]);
            pr[i] = max(-prices[i], pr[i-1]);
        }
        return max(dp[n-1], 0);
    }
};