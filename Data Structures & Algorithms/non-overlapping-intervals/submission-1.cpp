class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int n = intervals.size();
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i=0;i<n;i++)
            cout<<i<<" "<<intervals[i][0]<<" "<<intervals[i][1]<<endl;

        for(int i=1;i<n;i++)
        {
            int max_idx = -1;
            int l = 0;
            int r = i-1;
            int mid = (l+r)/2;

            while(l<=r)
            {
                mid = (l+r)/2;
                cout<<i<<" "<<mid<<" "<<intervals[i][0]<<" "<<intervals[mid][1]<<" "<<(intervals[i][0]>=intervals[mid][1])<<endl;
                if(intervals[i][0]>=intervals[mid][1])
                {
                    max_idx = mid;
                    l = mid+1;
                }
                else
                    r = mid-1;
            }

            if(max_idx!=-1)
            {
                dp[i] = dp[max_idx]+1;
            }
            cout<<i<<" "<<max_idx<<endl;

            dp[i] = max(dp[i],dp[i-1]);
        }

        return n-dp[n-1];
    }
};
