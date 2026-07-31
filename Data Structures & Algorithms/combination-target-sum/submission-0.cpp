class Solution {
    set<vector<int>> ans;
public:
    void rec(vector<int> nums, int ind, int target,int sum,vector<int> cur)
    {   
        int n = nums.size();

        if(ind>=n)
            return;

        rec(nums,ind+1,target,sum,cur);

        
        if(sum+nums[ind]<target)
        {
            cur.push_back(nums[ind]);
            rec(nums,ind,target,sum+nums[ind],cur);
            rec(nums,ind+1,target,sum+nums[ind],cur);   
        }

        if(sum+nums[ind]==target)
        {
            cur.push_back(nums[ind]);
            ans.insert(cur);
            return;
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        rec(nums,0,target,0,{});
        vector<vector<int>>ans2;
        for(auto it:ans)
            ans2.push_back(it);
        return ans2;
    }
};
