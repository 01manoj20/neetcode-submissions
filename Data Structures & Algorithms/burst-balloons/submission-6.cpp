using ll = long long;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        vector<ll> nums_m;
        nums_m.push_back(1);
        for(auto n:nums)
            nums_m.push_back(n);
        nums_m.push_back(1);

        ll n = nums.size();

        vector<vector<ll>> dp(n+2,vector<ll> (n+2,0));

        for(int i=n;i>=1;i--)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=i;k<=j;k++)
                {

                
                    ll selection = nums_m[k]*nums_m[i-1]*nums_m[j+1];
                    selection += (dp[i][k-1]+dp[k+1][j]);

                    dp[i][j] = max(dp[i][j],selection);

                    // cout<<i<<" "<<j<<" "<<k<<" "<<selection<<endl;
                    // break;

                }
            }
        }

        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=n+1;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }

        return dp[1][n];


        
    }
};
