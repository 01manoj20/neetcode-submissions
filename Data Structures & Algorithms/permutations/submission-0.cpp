class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return {{}};

        vector<vector<int>> ans;

        vector<int> temp = vector<int>(nums.begin()+1,nums.end());
        vector<vector<int>> perms = permute(temp);

        for(const auto p:perms)
        {
            for(int i=0;i<=p.size();i++)
            {
                vector<int> cpy = p;
                cpy.insert(cpy.begin()+i,nums[0]);
                ans.push_back(cpy);
            }
        }

        return ans;

        
    }
};
