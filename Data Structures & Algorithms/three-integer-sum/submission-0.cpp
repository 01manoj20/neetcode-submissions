class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        set<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        map<int,vector<int>> mp;
        int i = 0;
        for(auto num:nums)
            mp[num].push_back(i++);

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(auto pos:mp[-(nums[i]+nums[j])])
                    if(pos>j)
                    {
                        ans.insert({nums[i],nums[j],nums[pos]});
                        break;
                    }
            }
        }
        vector<vector<int>> finals;

        for(auto vect:ans)
            finals.push_back(vect);
            
        return finals;
    }
};
