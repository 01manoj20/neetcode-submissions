class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        map<int,vector<int>> mp;
        cout<<"HI";
        int i=0;
        for(auto elm:numbers)
        {
            mp[elm].push_back(i++);
        }

        for(auto elm:numbers)
        {
            cout<<elm<<" "<<target-elm<<endl;
            // cout<<mp[target-elm].size()<<" "<<mp[target-elm][0]<<endl;
            if(target == 2*elm)
            {
                if(mp[elm].size()>1)
                {
                    return {mp[elm][0]+1, mp[elm][1]+1};
                }
            }
            else
            {
                if(mp[target-elm].size()>0)
                    return{mp[elm][0]+1,mp[target-elm][0]+1};
            }
        }

        return {0,0};

    }
};
