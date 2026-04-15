using ll = long long;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        ll n = nums.size();
        vector<vector<ll>> dp(n,vector<ll>(2001,0));

        dp[0][nums[0]+1000]++;
        dp[0][1000-nums[0]]++;


        for(int i=1;i<n;i++)
        {
            for(int j=0;j<2001;j++)
            {
                ll cur = nums[i];

                if(dp[i-1][j])
                {
                    if(j-1000+cur<=1000)
                        dp[i][j+cur]+=dp[i-1][j];

                    if(j-1000-cur>=-1000)
                        dp[i][j-cur]+=dp[i-1][j];     
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=-10;j<10;j++)
            {
                cout<<dp[i][j+1000]<<" ";
            }
            cout<<endl;
        }
        return dp[n-1][target+1000];

    }
};
