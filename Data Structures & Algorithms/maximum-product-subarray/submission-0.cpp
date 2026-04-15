using ll = long long;
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        ll n = nums.size();

        vector<ll> max_dp(n,0);
        vector<ll> min_dp(n,0);

        max_dp[0] = nums[0];
        min_dp[0] = nums[0];

        ll ans = max_dp[0];

        for(int i=1;i<n;i++)
        {
            ll val_1 = nums[i]*max_dp[i-1];
            ll val_2 = nums[i]*min_dp[i-1];

            max_dp[i] = max(val_1,val_2);
            min_dp[i] = min(val_1,val_2);

            max_dp[i] = max(max_dp[i],nums[i]*1ll);
            min_dp[i] = min(min_dp[i],nums[i]*1ll);

            ans = max(ans,max_dp[i]);
        }
        
        return ans;
    }
};
