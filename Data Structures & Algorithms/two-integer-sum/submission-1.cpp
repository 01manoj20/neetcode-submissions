class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]].push_back(i);

        for(int i=0;i<n;i++)
        {
            if(target == nums[i]*2)
            {
                if(mp[nums[i]].size() == 2)
                    return {i,mp[nums[i]][1]};
                else
                    continue;
            }
            if(mp[target-nums[i]].size()!=0)
            {
                return {i,mp[target-nums[i]][0]};
            }
        }
    }
};
