using ll = long long; 
class Solution {
public:
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    // store grid and visited as members
    vector<vector<int>> g;
    bool visited[100][100];

    Solution() {
    std::fill(&visited[0][0], &visited[0][0] + 100*100, false);
    }

    bool inside(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(int x, int y, int n, int m, int& area) {
        visited[x][y] = true;
        area++;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (inside(nx, ny, n, m) && g[nx][ny] && !visited[nx][ny]) {
                dfs(nx, ny, n, m, area);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        g = grid;
        int n = g.size();
        int m = g[0].size();
        int max_area = 0;

        // ensure visited is truly reset for this run
        // memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] && !visited[i][j]) {
                    int area = 0;
                    dfs(i, j, n, m, area);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};
