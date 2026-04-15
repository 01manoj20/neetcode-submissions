using ll = long long;

class Solution {
public:
    
    ll dp[1010][1010];


    string longestPalindrome(string s) {

        ll l = s.length();
        ll ans_ind = 0;
        ll ans_len = 1;

        vector<vector<bool>> dp(l,vector<bool> (l,false));

        for(int i=l-1;i>=0;i--)
        {
            for(int j=i;j<l;j++)
            {
               

                if(s[i] == s[j])
                {
                    if(j-i<=2 || dp[i+1][j-1])
                    {
                        dp[i][j] = true;

                        if(j-i+1>ans_len)
                        {
                            ans_ind = i;
                            ans_len = j-i+1;
                        }
                    }

                    cout<<i<<" "<<j<<" "<<ans_ind<<" "<<ans_len<<endl;
                }

                
            }
        }

        return s.substr(ans_ind,ans_len);

    }

   
};
