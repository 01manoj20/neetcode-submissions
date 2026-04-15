class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==0)
            return 0;
        int ans = 1;
        int cur = 1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]<2)
            {
                cur+=(nums[i]-nums[i-1]);
                ans = max(ans,cur);
            }
            else
                cur = 1;
        }

        return ans;

    }
};
