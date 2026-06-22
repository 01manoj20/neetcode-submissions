/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto& a, auto& b) {
            return a.end < b.end;
        });

        vector<bool> can_use(n,true);

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            
            int l = 0;
            int r = i-1;

            int mid; 
            int this_ans = -1;

            while(l<=r)
            {
                mid = (l+r)/2;
                if((intervals[i].start>=intervals[mid].end)){
                    if(can_use[mid])
                        this_ans = mid;
                    l = mid+1;
                }
                else
                    r = mid-1;
            }

            cout<<intervals[i].start<<" "<<intervals[i].end<<" "<<this_ans<<endl; 
            if(this_ans == -1)
                ans++;
            else
                can_use[this_ans] = false;

        }

        return ans;
    }
};
