class Solution {
    vector<vector<int>> ans;
    
    
public:
    void create_subset(vector<int> nums, vector<int> cur, int i){
        if(i>=nums.size())
            return;
        else
        {
            create_subset(nums,cur,i+1);
            cur.push_back(nums[i]);
            ans.push_back(cur);
            create_subset(nums,cur,i+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        ans.push_back({});
        create_subset(nums,cur,0);
        return ans;
    }
};
