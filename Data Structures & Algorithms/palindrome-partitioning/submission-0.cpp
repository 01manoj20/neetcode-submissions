class Solution {
public:
    vector<vector<string>> ans;

    bool palindrome(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;r--;
        }
        return true;
    }
    
    void rec(int i, int j,string s, vector<string> cur)
    {
        // cout<<"function "<<i<<" "<<j<<endl;
        int n = s.length();
        
        
        if((j >= n))
        {
            if(j==i)
                ans.push_back(cur);
            return;
        }
        

        if(palindrome(s,i,j))
        {
            cur.push_back(s.substr(i,j-i+1));
            rec(j+1,j+1,s,cur);
            cur.pop_back();
        }
        rec(i,j+1,s,cur);
    }

    vector<vector<string>> partition(string s) 
    {
        vector<string> cur;
        rec(0,0,s,cur);
        return ans;
    }
};
