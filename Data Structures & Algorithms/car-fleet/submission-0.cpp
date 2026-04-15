class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = speed.size();

        vector<pair<int,int>> pos_speed;

        for(int i=0;i<n;i++)
            pos_speed.push_back({position[i],speed[i]});

        sort(pos_speed.begin(),pos_speed.end());

        vector<double> time(n,0);

        for(int i=0;i<n;i++)
        {
            time[i] = (double)(target -pos_speed[i].first)/(double)(pos_speed[i].second);
        }

        for(int i=n-2;i>=0;i--)
            time[i] = max(time[i],time[i+1]);

        double cur_time = time[0];
        int ans = 1;

        for(int i=1;i<n;i++)
        {
            if(cur_time!=time[i])
            {
                cur_time = time[i];
                ans++;
            }
        }

        for(auto t:time)
            cout<<t<<" ";

        cout<<endl;

        return ans;


    }
};
