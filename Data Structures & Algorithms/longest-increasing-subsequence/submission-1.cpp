using ll = long long;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        ll n = nums.size();
        vector<ll> dp(n,1);

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }

            // cout<<i<<" "
        }

        ll ans = -1;
        for(auto d:dp)
            ans = max(ans,d);

        return ans;
        // return *max_element(dp)

        
    }
};
