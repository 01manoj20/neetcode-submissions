class Solution {
public:
    string minWindow(string s, string t) {

        map<char,int> freq_t;

        for(auto c:t)
            freq_t[c]++;
        
        int n = s.size();
        int m = t.size();

        int t_unique = freq_t.size();

        map<char,int> cur_freq;
        int cur_match = 0;
        int l = 0;

        int ans = 1e9;
        pair<int,int> ans_ind = {-1,-1};

        for(int r = 0;r<n;r++)
        {
            cur_freq[s[r]]++;

            if(freq_t[s[r]] && (cur_freq[s[r]] == freq_t[s[r]]))
            {
                cur_match ++;
            }

            while(cur_match == t_unique)
            {
                if(r-l+1<ans)
                {
                    ans = r-l+1;
                    ans_ind = {l,r};
                }

                cur_freq[s[l]]--;

                if(freq_t[s[l]] && cur_freq[s[l]]<freq_t[s[l]])
                    cur_match--;

                l++;
            }   

        }

        return ans == 1e9 ? "":s.substr(ans_ind.first,ans);
    }
};
