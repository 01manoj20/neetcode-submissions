using ll = long long;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        ll n = grid.size();
        ll m = grid[0].size();

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        bool visited[n][m];

        ll distance[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                distance[i][j] = 2147483647;
                visited[i][j] = false;
            }
        }

        queue<pair<ll,ll>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    distance[i][j] = 0;

                }
            }
        }

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            visited[cur.first][cur.second] = true;
     
            ll cur_dis = distance[cur.first][cur.second];

            for(int i=0;i<4;i++)
            {
                ll n_x = cur.first+dx[i];
                ll n_y = cur.second+dy[i];

                 

                if((n_x>=0) && (n_x<n) && (n_y>=0) && (n_y<m))
                {
                    if((grid[n_x][n_y]!=0) && (!visited[n_x][n_y]))
                    {
                        distance[n_x][n_y] = min(distance[n_x][n_y],cur_dis+1);
                        q.push({n_x,n_y});
                    }
                }
            }
        }

        ll ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                    ans = max(ans,distance[i][j]);
            }
        }

        if(ans == 2147483647)
            return -1;
        else
            return ans;
        
    }
};
