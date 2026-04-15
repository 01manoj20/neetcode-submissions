class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char,int> mp;

        int distinct = 0;
        
        int head = -1;
        int ans = 0;

        for(int tail = 0;tail<n;tail++ )
        {
            while(head<n)
            {
                if(mp[s[head+1]] == 0)
                {
                    mp[s[head+1]]++;
                    head++;
                }
                else
                    break;
            }
            head = min(head,n-1);
            if(head<tail)
                head = tail;
            else
                ans = max(head-tail+1,ans);

            cout<<ans<<" "<<tail<<" "<<head<<endl;

            mp[s[tail]]--;

        }

        return ans;
        
    }
};
