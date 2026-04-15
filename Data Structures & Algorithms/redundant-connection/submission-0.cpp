class DSU{

    vector<int> parent, size;
    int comps;


    public:
        DSU(int n)
        {
            comps = n;
            parent.resize(n+1);
            size.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i] = i;
                size[i] = 1;
            }

        }



        int find(int u)
        {
            if(parent[u]!=u)
                return find(parent[u]);

            return u;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(101);
        vector<int> ans;
        for(auto it:edges)
        {
            if(!dsu.merge(it[0],it[1]))
                ans = it;
        }

        return ans;
    }
};
