class Solution {
public:
    bool check_valid_pos(vector<vector<char>>& board, int i, int j)
    {
        int cur_num = board[i][j]-'0';
        for(int x=0;x<9;x++)
        {
            if(x == i)
                continue;
            if(board[x][j]-'0' == cur_num){
                cout<<"Reason 1 "<<x<<" "<<endl;
                return false;
            }
        }

        for(int x=0;x<9;x++)
        {
            if(x==j)    continue;
            if(board[i][x]-'0' == cur_num){
                cout<<"Reason 2 "<<x<<" "<<endl;
                return false;
            }
        }

        int l = i/3;
        int m = j/3;

        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                if(((l*3+x)==i) && ((m*3+y)==j))
                    continue;
                if(board[l*3+x][m*3+y] -'0' == cur_num){
                    cout<<"Reason 3 "<<l*3+x<<" "<<m*3+y<<endl;
                    return false;
                }
            }
        }

        return true;
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.'){
                    cout<<"skip "<<i<<" "<<j<<endl;
                    continue;
                }
                if(!check_valid_pos(board,i,j)){
                    cout<<i<<" "<<j<<endl;
                    return false;
                }
            }
        }

        return true;

        
    }
};
