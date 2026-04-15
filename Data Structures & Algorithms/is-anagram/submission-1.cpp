class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int> mp;
        for(auto c:s)
            mp[c-'a']++;
        
        for(auto c:t)
            mp[c-'a']--;

        for(int i=0;i<26;i++)
        {
            if(mp[i]!=0)
                return false;
        }

        return true;
    }
};
