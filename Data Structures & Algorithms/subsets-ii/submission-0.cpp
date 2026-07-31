class Solution {
public:
    vector<vector<int>> ans;

    void rec(vector<int> nums, int ind, vector<int> subset)
    {
        if(ind == nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[ind]);
        rec(nums,ind+1,subset);

        subset.pop_back();
        while(((ind+1)<nums.size()) && (nums[ind] == nums[ind+1]))
            ind++;
        
        rec(nums,ind+1,subset);

        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        rec(nums,0,{});
        return ans;
    }
};
