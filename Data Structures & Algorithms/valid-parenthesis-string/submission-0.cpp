class Solution {
public:
    bool checkValidString(string s) {
        int n= s.length();
        int maxx(0),minn(0);
        for(int i=0;i<n;i++)
        {
            if(s[i] == '('){
                maxx++;
                minn++;
            }
            else if(s[i] == ')'){
                maxx--;
                minn--;
            }
            else{
                maxx++;
                minn--;
            }

            if(maxx<0)
                return false;

            if(minn<0)
                minn = 0;
        }

        if(minn == 0)
            return true;
        return false;


        
    }
};
