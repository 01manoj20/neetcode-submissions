using ll = long long;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<ll> dp(10010,1e9);
        cout<<"hi"<<endl;
        if(amount == 0)
            return 0;

        ll n = coins.size();

        for(int k=0;k<n;k++){
            if(coins[k]<10010){
                cout<<"hi"<<endl;
                dp[coins[k]] = 1;
            }
        }

        for(ll i=1;i<10010;i++)
        {

            for(ll k=0;k<n;k++)
            {
                // if(i == 10009)
                //     cout<<i+coins[k]<<endl;

                if(i+coins[k] < 10010)
                    dp[i+coins[k]] = min(dp[i+coins[k]],1+dp[i]);
            }
        }

        

        return dp[amount]!=1e9 ? dp[amount]:-1;
    }
};
