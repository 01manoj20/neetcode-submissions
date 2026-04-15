using ll = long long;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        ll n = prices.size();

        vector<vector<ll>> dp(n,vector<ll> (3,0));

        dp[0][0] = -prices[0];

        for(int i=1;i<n;i++)
        {
            ll cur_price = prices[i-1];

            dp[i][0] = max(dp[i-1][2]-prices[i],dp[i-1][0]);
            dp[i][1] = dp[i-1][0]+prices[i];
            dp[i][2] = max(dp[i-1][1],dp[i-1][2]);
        }

        for(int j=0;j<3;j++)
        {
            for(int i=0;i<n;i++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }

        return max(dp[n-1][1],dp[n-1][2]);
    }
};
