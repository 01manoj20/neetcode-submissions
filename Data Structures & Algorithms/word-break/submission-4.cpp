using ll = long long;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        ll n = s.length();
        map<string,int> mp;
        
        for(auto wo:wordDict)
            mp[wo]++;


        vector<ll> dp(n,0);
      

        for(int i=0;i<n;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if((dp[j] == 1)) 
                {
                    string cur_word = "";
                    for(int k=j+1;k<=i;k++)
                        cur_word+=s[k];
                    cout<<cur_word<<" "<<endl;

                    if(mp[cur_word])
                    {
                        dp[i] = 1;
                        break;
                    }
                }
                if((j == 0))
                {
                    string cur_word = "";
                    for(int k=0;k<=i;k++)
                        cur_word+=s[k];

                    cout<<cur_word<<" "<<mp.count(cur_word)<<endl;
                
                    if(mp[cur_word])
                    {
                        dp[i] = 1;
                        break;

                    }
                }
            }

            cout<<i<<" "<<dp[i]<<endl;
        }

        return dp[n-1];

    }
};
