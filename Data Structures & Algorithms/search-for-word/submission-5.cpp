class Solution {
public:
    bool valid(int i,int j, int n,int m)
    {
        return ((i<n)&&(j<m)&&(i>=0)&&(j>=0));
    }

    bool rec(int i,int j,vector<vector<char>>& board, string word,int ind,int n,int m,vector<vector<bool>> visited)
    {

        
        int dx[] = {-1,1,0,0};
        int dy[]= {0,0,1,-1};

        visited[i][j] = true;

        if(ind == word.size())
            return true;
        
        if(valid(i,j,n,m)&&(ind<word.size()))
        {
            cout<<i<<" "<<j<<" "<<board[i][j]<<" "<<ind<<endl;
            
            // cout<<board[i][j]<<" "<<word[ind]<<endl; 
            if(board[i][j] == word[ind])
            {
                if(ind == word.size()-1)
                    return true;
                
                cout<<" yes \n";
                for(int k=0;k<4;k++)
                {
                     if(valid(i+dx[k],j+dy[k],n,m) && (visited[i+dx[k]][j+dy[k]] == false) && rec(i+dx[k],j+dy[k],board,word,ind+1,n,m,visited))
                        return true;
                }
            }
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                if(rec(i,j,board,word,0,n,m,visited))
                    return true;
                
            }
        }

        return false;
        
    }
};
