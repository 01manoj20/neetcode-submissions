class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++)
        {
            if(i == 0){
                dp[0][0] = grid[0][0];
                for(int j=1;j<m;j++)
                        dp[i][j] = dp[i][j-1]+grid[i][j];
            } 
            else
            {
                for(int j=0;j<m;j++){
                    if(j == 0)
                        dp[i][j] = grid[i][j] + dp[i-1][j];
                    else
                        dp[i][j] = min(grid[i][j]+dp[i-1][j],grid[i][j]+dp[i][j-1]);
                }
            }
        }

        return dp[n-1][m-1];
        
    }
};