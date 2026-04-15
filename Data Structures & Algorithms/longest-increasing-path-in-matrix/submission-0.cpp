
using ll = long long;

class Solution {
public:

    ll n,m;

    ll dx[4] = {1,-1,0,0};
    ll dy[4] = {0,0,1,-1};

    bool visited[110][110];
    ll ans[110][110];

    bool valid(int x,int y)
    {
        if((x<0) || (y<0) || (x>=n) || (y>=m))
            return false;
        
        return true;
    }

    void dfs(int x,int y,vector<vector<int>>& matrix)
    {
        cout<<"dfs entered:"<<x<<" "<<y<<endl;
        
        visited[x][y] = true;
        ans[x][y] = 1;

        

        for(int i=0;i<4;i++)
        {
            ll neigh_x = x+dx[i];
            ll neigh_y = y+dy[i];

            if(valid(neigh_x,neigh_y))
            {
                cout<<neigh_x<<" "<<neigh_y<<endl;
                
                
                if(matrix[neigh_x][neigh_y]>matrix[x][y])
                {
                    
                    if(!visited[neigh_x][neigh_y])
                    {
                        dfs(neigh_x,neigh_y,matrix);
                    }

                    ans[x][y] = max(ans[x][y],1+ans[neigh_x][neigh_y]);
                }

                
            }

        }

        cout<<"dfs returned:"<<x<<" "<<y<<" "<<ans[x][y]<<endl;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                visited[i][j] = false;

        n = matrix.size();
        m = matrix[0].size();

        // cout<<n<<" "<<m<<" ------\n";


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // cout<<i<<" "<<j<<endl;
                if(!visited[i][j])
                    dfs(i,j,matrix);
            }
        }

        ll final_ans=-1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                final_ans = max(final_ans,ans[i][j]);
            }
        }

        return final_ans;

    }
};
