class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto str:strs)
        {
            ans+=to_string((str.length()));
            ans+="@";
            ans+=str;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int n = s.length();
        int len = 0;
    
        for(int i=0;i<n;i++)
        {
            if(s[i] == '@')
            {
                cout<<len<<endl;
                string cur = s.substr(i+1,len); 
                ans.push_back(cur);
                i+=len;
                len = 0;
            }
            else
            {
                len*=10;
                len+=(s[i]-'0');

                cout<<s[i]<<" "<<len<<endl;
            }

        }

        return ans;


    }
};
