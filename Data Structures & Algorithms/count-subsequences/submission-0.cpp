using ll = long long;
class Solution {
public:
    int numDistinct(string s, string t) {

        ll n = s.length();
        ll m = t.length();

        ll dp[n+1][m+1];

        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j] = -1;

        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        
        for(int j=0;j<=m;j++)
            dp[0][j] =0;

        dp[0][0] = 1;


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }


        return dp[n][m];


        
    }
};
