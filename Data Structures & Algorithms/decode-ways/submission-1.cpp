using ll = long long;

class Solution {
public:
    int numDecodings(string s) {

        ll l = s.length();
        vector<ll> dp(l,0);

        if(s[0]!='0')
            dp[0] = 1;

        for(int i=1;i<l;i++)
        {
            if(s[i]!='0')
                dp[i]+=dp[i-1];

            if(s[i-1] -'0' == 1 || ((s[i-1]-'0' == 2) && ((s[i]-'0')<7))){
                if(i == 1)
                    dp[i]++;
                else
                    dp[i]+=dp[i-2];
            }
            
        }
        
        return dp[l-1];

    }
};
