class Solution {
public:

    bool cycle = false;
    vector<int> ans;

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
        ans.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(1010);
        vector<int> status(1010);
        vector<int> in_node(1010);
        for(int i=0;i<=1001;i++){
            status[i] = 0;
            in_node[i] = 0;
        }


        for(auto dep:prerequisites){
            G[dep[1]].push_back(dep[0]); 
            in_node[dep[0]]++;
        }

        
        for(int i=0;i<=numCourses;i++)
        if(!status[i])
            dfs(i,status,G);

        if(cycle)
            return {};


        
        queue<int> q;

        for(int i=0;i<numCourses;i++)
            cout<<in_node[i]<<" ";

        cout<<endl;

        for(int i=0;i<numCourses;i++)
        {
            if(in_node[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
    
            for(auto neigh:G[node])
            {
                in_node[neigh]--;
                if(in_node[neigh] == 0)
                    q.push(neigh);
            }


            q.pop();
            in_node[node] = -1;
            ans.push_back(node);

        }

        // reverse(ans.begin(),ans.end())

        return ans;

        

    }
};
