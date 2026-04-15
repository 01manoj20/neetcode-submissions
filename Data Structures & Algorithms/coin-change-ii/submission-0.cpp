using ll = long long;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        ll n = coins.size();
        vector<vector<ll>> dp(n,vector<ll>(5001,0));

        ll cur = 0;
        while(cur<=5000)
        {
            dp[0][cur] = 1;
            cur+=coins[0];
        }

        for(int i=1;i<n;i++)
        {
            int cur_coin = coins[i];

            for(int j=0;j<5001;j++)
            {
                dp[i][j] = dp[i-1][j];

                if(j>=coins[i])
                    dp[i][j] += dp[i][j-cur_coin];
            }
            
        }

        return dp[n-1][amount];


    }
};
