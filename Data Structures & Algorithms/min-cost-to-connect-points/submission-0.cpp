class DSU{

    public:
        vector<int> parent,size;

        DSU(int n):parent(n+1),size(n+1,1)
        {
            for(int i=0;i<n;i++)
                parent[i] = i;
        }

        int find(int node)
        {
            if(parent[node]!=node)
                parent[node] = find(parent[node]);
            
            return parent[node]; 
        }

        bool merge(int u, int v)
        {
            int pu = find(u);
            int pv = find(v);

            if(pu == pv)
                return false;

            if(size[pu]<size[pv])
                swap(pu,pv);
            
            size[pu]+=size[pv];
            parent[pv] = pu;

            return true;
        }
};



class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        DSU dsu(n);

        vector<vector<int>>edges;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        }

        sort(edges.begin(),edges.end());

        int cost = 0;

        for(auto e:edges)
        {
            int u = e[1];
            int v = e[2];
            int dist = e[0];

            if(dsu.merge(u,v))
            {
                cost+=dist;
            }
        }

        return cost;

        
    }
};
