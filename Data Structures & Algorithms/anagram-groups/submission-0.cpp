class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        // vector<vector<int>> freq(n,vector<int>(26,0));

        // int ind = 0;

        
        map<vector<int>,vector<string>> mp;
        for(auto str:strs)
        {
            vector<int> freq(26,0);
            for(char c:str)
                freq[c-'a']++;

            mp[freq].push_back(str);

        }



        for(auto m:mp)
        {
            vector<string> ana;
            for(auto str:m.second)
                ana.push_back(str);
            
            ans.push_back(ana);

        }
        
        return ans;
    }
};
