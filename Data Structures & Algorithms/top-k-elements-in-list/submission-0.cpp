class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto elm:nums)
            mp[elm]++;

        vector<pair<int,int>> freq;

        for(auto m:mp)
            freq.push_back({m.second,m.first});

        sort(freq.begin(),freq.end());
        reverse(freq.begin(),freq.end());

        vector<int> ans;

        for(int i=0;i<k;i++)
            ans.push_back(freq[i].second);

        return ans;
    }
};
