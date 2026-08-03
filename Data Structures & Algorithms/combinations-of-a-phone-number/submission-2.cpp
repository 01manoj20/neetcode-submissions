class Solution {
public:
    vector<string> ans;

    void rec(int ind, string digits, vector<string> cur)
    {
        if(ind == digits.length())
        {
            cout<<"reached\n";
            for(auto word: cur){
                cout<<word<<endl;
                ans.push_back(word);
            }
            return;
        }

        vector<char> cur_pos;
        int i = digits[ind]-'0';

        

        if(digits[ind] == '9')
            cur_pos = {'w','x','y','z'};
        else if(digits[ind]== '7')
            cur_pos = {'p','q','r','s'};
        else if(digits[ind] == '8')
            cur_pos = {'t','u','v'};
        else
        {
            for(int k=0;k<3;k++)
            {
                cur_pos.push_back('a'+((i-2)*3)+k);
            }
        }
        vector<string> new_cur;

        for(auto c:cur_pos)
        {
            cout<<c<<endl;
            for(auto word:cur){
                word+=c;
                cout<<"word--"<<word<<endl;
                new_cur.push_back(word);

            }
        }

        rec(ind+1,digits,new_cur);

    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};

        rec(0,digits,{""});
        return ans;
    }
};
