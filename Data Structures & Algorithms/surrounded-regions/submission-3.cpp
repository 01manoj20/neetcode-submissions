using ll = long long;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        ll n = board.size();
        ll m = board[0].size();

        bool visited1[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                visited1[i][j] = false;
            }
        }
        ll dx[4] = {1,-1,0,0};
        ll dy[4] = {0,0,1,-1};

        queue<pair<ll,ll>> q;

        for(int i=0;i<n;i++)
        {
            if(board[i][0] != 'X')
                q.push({i,0});
        }

        for(int i=0;i<n;i++)
        {
            if(board[i][m-1] != 'X')
                q.push({i,m-1});
        }

        for(int i=0;i<m;i++)
        {
            if(board[n-1][i] != 'X')
                q.push({n-1,i});
        }

        for(int i=0;i<m;i++)
        {
            if(board[0][i] != 'X')
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
                    if((board[n_x][n_y] == 'O') && (!visited1[n_x][n_y]))
                    {
                        q.push({n_x,n_y});
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'O')
                {
                    if(!visited1[i][j])
                        board[i][j] = 'X';
                }
            }
        }
    }
};
