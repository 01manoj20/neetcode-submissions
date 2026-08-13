class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n =s.length();

        map<char,int> mp;
        for(int i=0;i<26;i++)
            mp['a'+i] =-1;
    
        for(int i=0;i<n;i++)
            mp[s[i]] = i;
        
        vector<int> ends(n,-1);
        for(int i=0;i<n;i++)
            ends[i] = mp[s[i]];


        int cur_s = 0;
        int cur_end = -1;
        int cur = cur_s;

        int count;

        vector<int> ans;

        while(cur_s<n)
        {
            

            cur_end = ends[cur_s];
            cur = cur_s;
            while((cur<n) && (cur<=cur_end)){
                cur_end = max(cur_end,ends[cur]);
                cur++;
            }

            ans.push_back(cur_end-cur_s+1);
            cur_s = cur_end+1;
        }

        return ans;

    }
};
