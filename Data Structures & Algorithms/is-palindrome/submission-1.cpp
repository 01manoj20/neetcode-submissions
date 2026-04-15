class Solution {
public:


    bool isPalindrome(string s) {
        int n = s.length();
        for(auto& x:s)
            x = tolower(x);

        int l = 0;
        int r = n-1;

        while(l<=r)
        {
            while(!isalnum(s[l]))
                l++;
            
            while(!isalnum(s[r]))
                r--;

            if(l<=r){
                if(s[l]!=s[r])
                    return false;

                l++;
                r--;
            }
        }
        
        return true;

        

    }
};
