using ll = long long;
class Solution {
public:
    vector<vector<pair<int,int>>>G;
    vector<int> distance;

    void djkstra(int node)
    {
        distance[node] = 0;
        priority_queue<pair<int,int>> pq;
        pq.push({0,node});


        while(!pq.empty())
        {
            auto cur = pq.top();
            int cur_dis = -cur.first;

            for(auto neigh:G[cur.second])
            {
                if(cur_dis+neigh.second<distance[neigh.first])
                {
                    distance[neigh.first] = cur_dis+neigh.second;
                    pq.push({-distance[neigh.first],neigh.first});
                }
            }

            pq.pop();

        }

    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        G.resize(n+1);
        distance.resize(n+1,1e9);
        for(auto t:times)
            G[t[0]].push_back({t[1],t[2]});

        djkstra(k);
        int ans =0;
        for(int i=1;i<=n;i++)
            ans = max(ans,distance[i]);

        if(ans == 1e9)
            return -1;

        return ans;

    }
};
