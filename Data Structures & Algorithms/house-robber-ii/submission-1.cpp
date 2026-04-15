using ll = long long;

class Solution {
public:
    int rob(vector<int>& nums) {

        
        ll n = nums.size();
        if(n == 1)
            return nums[0];
            
        vector<ll> dp(n,0);

        dp[0] = nums[0];
        dp[1] = nums[0];

        for(int i=2;i<n;i++)
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);



        vector<ll> dp_2(n,0);

        dp_2[0] = 0;
        dp_2[1] = nums[1];

        for(int i=2;i<n;i++)
            dp_2[i] = max(dp_2[i-1],dp_2[i-2]+nums[i]);

        return max(dp[n-2],dp_2[n-1]);


    }
};
