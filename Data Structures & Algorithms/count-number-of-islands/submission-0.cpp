class Solution {
public:
    

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    // vector<vector<bool>> visited(100, vector<bool>(100, false));

    bool visited[110][110];


    bool valid(int x,int y,int n,int m,vector<vector<char>>& grid)
    {
        
        if(x>=0 && x<n)
            if(y>=0 && y<m)
                if(grid[x][y] == '1')
                    return true;
        
        return false;
    }

    void dfs(int x,int y,int n,int m,vector<vector<char>>& grid)
    {
        cout<<x<<" "<<y<<" dfs executing"<<endl;
        visited[x][y] = true;
        for(int i=0;i<4;i++)
        {
            int neigh_x = x+dx[i];
            int neigh_y = y+dy[i];

            cout<<neigh_x<<" "<<neigh_y<<" "<<valid(neigh_x,neigh_y,n,m,grid)<<endl;

            if(valid(neigh_x,neigh_y,n,m,grid))
            {
                if(!visited[neigh_x][neigh_y])
                    dfs(neigh_x,neigh_y,n,m,grid);
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
                visited[i][j] = false;

        int ans = 0;
        cout<<n<<" "<<m<<endl;

        // dfs(0,0,n,m,grid);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<i<<" "<<j<<" "<<valid(i,j,n,m,grid)<<" "<<!visited[i][j]<<endl;
                if((valid(i,j,n,m,grid)) && (!visited[i][j])){
                    ans++;
                    dfs(i,j,n,m,grid);
                }
            }
        }

    return ans;

    }
};
