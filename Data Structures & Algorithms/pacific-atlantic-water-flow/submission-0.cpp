using ll = long long;

class Solution {
public:

    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ll n = heights.size();
        ll m = heights[0].size();

        bool visited1[n][m];
        bool visited2[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                visited1[i][j] = false;
                visited2[i][j] = false;
            }
        }
        ll dx[4] = {1,-1,0,0};
        ll dy[4] = {0,0,1,-1};

        queue<pair<ll,ll>> q;

        for(int i=0;i<n;i++)
        {
            q.push({i,0});
        }

        for(int i=0;i<m;i++)
        {
            q.push({0,i});
        }

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            visited1[cur.first][cur.second] = true;
     

            for(int i=0;i<4;i++)
            {
                ll n_x = cur.first+dx[i];
                ll n_y = cur.second+dy[i];

                 

                if((n_x>=0) && (n_x<n) && (n_y>=0) && (n_y<m))
                {
                    if((heights[n_x][n_y]>=heights[cur.first][cur.second]) && (!visited1[n_x][n_y]))
                    {
                        q.push({n_x,n_y});
                    }
                }
            }
        }




        for(int i=0;i<n;i++)
        {
            q.push({i,m-1});
        }

        for(int i=0;i<m;i++)
        {
            q.push({n-1,i});
        }

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            visited2[cur.first][cur.second] = true;
     

            for(int i=0;i<4;i++)
            {
                ll n_x = cur.first+dx[i];
                ll n_y = cur.second+dy[i];

                 

                if((n_x>=0) && (n_x<n) && (n_y>=0) && (n_y<m))
                {
                    if((heights[n_x][n_y]>=heights[cur.first][cur.second]) && (!visited2[n_x][n_y]))
                    {
                        q.push({n_x,n_y});
                    }
                }
            }
        }

        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited1[i][j] && visited2[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
        

    }
};
