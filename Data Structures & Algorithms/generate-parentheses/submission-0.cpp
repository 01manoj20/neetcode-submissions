class Solution {
public:
    vector<string> ans;
    void rec(int ind, string cur, int sum,int n)
    {
        if(ind == 2*n)
        {
            if(sum == 0)
                ans.push_back(cur);
            return;
        }

        rec(ind+1,cur+'(',sum+1,n);

        if(sum>0)
            rec(ind+1,cur+')',sum-1,n);

    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        rec(0,cur,0,n);

        return ans;
    }
};
