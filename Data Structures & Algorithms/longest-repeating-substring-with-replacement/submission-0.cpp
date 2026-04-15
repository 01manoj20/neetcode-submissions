class Solution {
public:
    int characterReplacement(string s, int k) 
    {

        int n = s.length();
        
        
        
        
        int final_ans = -1;
        
        for(int c=0;c<26;c++)
        {
            int head = -1;
            int ans = 0;
            int distinct = 0;

            for(int tail = 0;tail<n;tail++)
            {
                while(head<n)
                {
                    if(s[head+1]!='A'+c)
                    {
                        if(distinct<k){
                            distinct++;
                            head++;
                        }
                        else
                            break;
                    }
                    else
                        head++;  
                }

                if(head == n)
                    ans = max(head-tail,ans);
                else{
                    ans = max(head-tail+1,ans);
                }

                if(head<tail)
                    head = tail;

                cout<<ans<<" "<<head<<" "<<tail<<endl;

                if(s[tail]!='A'+c)
                    distinct--;
                

            }

            final_ans = max(final_ans,ans);
        
        }
        
        return final_ans;
        
    }
};
