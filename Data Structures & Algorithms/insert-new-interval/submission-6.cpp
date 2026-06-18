class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n= intervals.size();
        // if(n==0)
        //     return {newInterval};

        int flag =1;
        for(int i=0;i<n;i++)
        {
            // if((intervals[i][0]<newInterval[0] && intervals[i][1]>newInterval[0]) || 
            //     (intervals[i][0]<newInterval[1] && intervals[i][1]>newInterval[1]) )
            // {
            //     intervals[i][0] = min(intervals[i][0],newInterval[0]);
            //     intervals[i][1] = max(intervals[i][1],newInterval[1]);
            // }
            if((intervals[i][0]>newInterval[0]))
            {
                intervals.insert(intervals.begin()+i,newInterval);
                flag =0;
                break;
            }

        }

        if(flag)
            intervals.push_back(newInterval);

        for(auto interval:intervals)
            cout<<interval[0]<<" "<<interval[1]<<endl;
       

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
