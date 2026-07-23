class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1e9);

        ans[n-1] = 0;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=nums[i];j++)
            {
                if((i+j)<=n-1)
                {
                    ans[i] = min(ans[i],1+ans[i+j]);
                }
            }
        }

        return ans[0];
    }
};
