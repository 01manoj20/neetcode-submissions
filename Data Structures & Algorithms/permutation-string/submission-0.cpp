class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        if(n>m)
            return false;

        vector<int> s1_freq(26,0);
        vector<int> s2_freq(26,0);

        for(int i=0;i<n;i++)
            s1_freq[s1[i]-'a']++;

        for(int i=0;i<26;i++)
            cout<<s1_freq[i];
        cout<<endl;


        for(int i=0;i<n-1;i++)
            s2_freq[s2[i]-'a']++;

        for(int i=0;i<26;i++)
            cout<<s2_freq[i];
        cout<<endl;

        int tail = 0;
        for(int i=n-1;i<m;i++)
        {
            s2_freq[s2[i]-'a']++;

            for(int i=0;i<26;i++)
                cout<<s2_freq[i];
            cout<<endl;

            int flag = 1;

            for(int j=0;j<26;j++)
            {
                cout<<s1_freq[j]<<" "<<s2_freq[j]<<endl;
                if(s1_freq[j]!=s2_freq[j])
                    flag = 0;
            }

            if(flag == 1)
                return true;

            s2_freq[s2[tail]-'a']--;

            tail++;
        }

        return false;
        
        
    }
};
