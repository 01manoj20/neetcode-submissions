class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++)
        {
            int cur_size = ans.size();
            cout<<ans[cur_size-1][0]<<" "<<ans[cur_size-1][1]<<endl;
            if(ans[cur_size-1][1]>=intervals[i][0]){
                ans[cur_size-1][1] = max(intervals[i][1],ans[cur_size-1][1]);
            }
            else
                ans.push_back(intervals[i]);
        }

        return ans;
    }
};
