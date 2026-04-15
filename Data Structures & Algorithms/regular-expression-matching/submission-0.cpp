using ll = long long;

class Solution {
public:
    bool isMatch(string s, string p) {

        ll n = s.length();
        ll m = p.length();

        vector<vector<ll>> dp(n+1,vector<ll> (m+1,0));

        dp[n][m] = 1;

        for(int i=n;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                ll match = ((i<n) && ((s[i] == p[j]) || (p[j] == '.')));

                if((j+1<m) && p[j+1] == '*')
                {
                    dp[i][j] = dp[i][j+2];
                    if(match)
                        dp[i][j] = (dp[i+1][j] | dp[i][j]);
                }
                else if(match)
                {
                    dp[i][j] = dp[i+1][j+1];
                }

            }
        }

        return dp[0][0];
        
    }
};
