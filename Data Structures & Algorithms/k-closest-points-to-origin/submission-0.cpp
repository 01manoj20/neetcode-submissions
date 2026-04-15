using ll = long long;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,pair<int,int>>> pq;

        for(auto pts: points)
        {
            int x = pts[0];
            int y = pts[1];

            pq.push({((x*x)+(y*y)), {x,y}});
        }

        while(pq.size()>k)
            pq.pop();



        vector<vector<int>> ans;

        while(pq.size())
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            ans.push_back({x,y});

            pq.pop();
        }

        return ans;

    }
};
