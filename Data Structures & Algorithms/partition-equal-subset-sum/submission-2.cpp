using ll = long long;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<vector<bool>> dp(100,vector<bool>(5001,false));

        ll n = nums.size();
        ll sum = 0;

        for(int i=0;i<n;i++)
            sum+=nums[i];

        dp[0][0] = true;
        dp[0][nums[0]] = true;

        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<5001;j++)
            {
                if(dp[i][j]){
                    dp[i+1][j] = true;
                    dp[i+1][j+nums[i+1]] = true;
                }
            }
        }
        
        if(sum%2)
            return false;

        for(int i=0;i<15;i++)
            cout<<dp[n-1][i];
        
        if(dp[n-1][sum/2])
            return true;


        return false;
        
    }
};
