class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(auto elm:nums)
        {
            if(mp[elm])
                return true;
            mp[elm]++;
        }
        return false;
    }
};