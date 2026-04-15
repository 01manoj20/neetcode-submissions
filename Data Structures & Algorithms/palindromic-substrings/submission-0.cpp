using ll = long long;
class Solution {
public:
    int countSubstrings(string s) {
        ll l = s.length();
      

        vector<vector<bool>> dp(l,vector<bool> (l,false));
        ll ans = 0;

        for(int i=l-1;i>=0;i--)
        {
            for(int j=i;j<l;j++)
            {
                if(s[i] == s[j])
                {
                    if(j-i<=2 || dp[i+1][j-1])
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                }
                
            }
        }

        return ans;
    }
};
