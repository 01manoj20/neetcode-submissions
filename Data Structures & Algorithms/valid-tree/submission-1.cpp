class Solution {
public:
    bool cycle = false;

    void dfs(int node, vector<int>& status, vector<vector<int>>& G,int parent)
    {
        cout<<"dfs "<<node<<endl;
        status[node] = 1;

        cout<<status[node]<<endl;

        for(auto neigh: G[node])
        {
            if(neigh == parent)
                continue;

            if(status[neigh] == 0)
                dfs(neigh,status,G,node);
            if(status[neigh] == 1)
                cycle = true;
        }

        status[node] = 2;

        cout<<node<<" end "<<status[node]<<endl;

    }
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size()>n-1)
            return false;
        
        vector<vector<int>> G(110);
        vector<int> status(110,0);

        for(auto elm:edges){
            G[elm[0]].push_back(elm[1]);
            G[elm[1]].push_back(elm[0]);
        }

        dfs(0,status,G,-1);

        for(int i=0;i<n;i++)
        {
            cout<<i<<" "<<status[i]<<endl;
            if(!status[i])
                cycle = true;
        }


        return !cycle;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    


    }
};
