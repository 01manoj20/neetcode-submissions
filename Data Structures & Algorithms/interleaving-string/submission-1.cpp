using ll = long long;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        ll n1 = s1.length();
        ll n2 = s2.length();
        ll n3 = s3.length();

        bool dp[n1+1][n2+1][n3];

        if((n1 == 0) && (n2 == 0) && (n3 == 0))
            return true;
        
        for(int k=0;k<n3;k++)
            for(int i=0;i<=n1;i++)
                for(int j=0;j<=n2;j++)
                    dp[i][j][k] = false;

        if(s3[0] == s2[0])
            dp[0][1][0] = true;
        if(s3[0] == s1[0])
            dp[1][0][0] = true;


        for(int k=0;k<n3;k++)
        {
            for(int i=0;i<=n1;i++)
            {
                for(int j=0;j<=n2;j++)
                {
                    // cout<<i<<" "<<j<<" "<<k<<":"<<endl;
                    if(dp[i][j][k])
                    {
                        if((i+1<=n1) && (s3[k+1] == s1[i])){
                            // cout<<i+1<<" "<<j<<" "<<k+1<<endl; 
                            dp[i+1][j][k+1] = true;
                        }
                        if((j+1<=n2) && (s3[k+1] == s2[j])){
                            // cout<<i<<" "<<j+1<<" "<<k+1<<endl;
                            dp[i][j+1][k+1] = true;
                        }
                        
                    }
                }
            }

        }

        return dp[n1][n2][n3-1];

    }
};
