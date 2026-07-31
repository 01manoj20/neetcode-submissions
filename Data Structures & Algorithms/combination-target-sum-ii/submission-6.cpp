class Solution {
public:
    vector<vector<int>> ans;

    void rec(vector<int>& candidates, int target, vector<int> cur,int sum,int ind)
    {
        int n = candidates.size();

        if(sum == target){
            ans.push_back(cur);
            return;
        }

        if(sum > target)
           return;

        if(ind >= n)
            return;

        
        cur.push_back(candidates[ind]);
        rec(candidates,target,cur,sum+candidates[ind],ind+1);

        cur.pop_back();
        while(((ind+1)<n) && (candidates[ind] == candidates[ind+1]))
            ind++;
            
        rec(candidates,target,cur,sum,ind+1);

        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        
        rec(candidates,target,{},0,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
