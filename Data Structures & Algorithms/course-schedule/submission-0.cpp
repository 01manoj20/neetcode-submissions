class Solution {
public:

    bool cycle = false;

    void dfs(int node, vector<int> status, vector<vector<int>>G)
    {
        status[node] = 1;

        for(auto neigh:G[node])
        {
            if(!status[neigh])
                dfs(neigh,status,G);
            
            if(status[neigh] == 1)
                cycle = true;
            
        }

        status[node] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(1010);
        vector<int> status(1010);

        for(auto dep:prerequisites)
            G[dep[1]].push_back(dep[0]); 

        for(int i=1;i<=1001;i++)
            status[i] = 0;

        for(int i=1;i<=1001;i++)
            if(!status[i])
                dfs(i,status,G);


        return !cycle;
        

    }
};
