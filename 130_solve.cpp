class Solution {
public:
    int m,n;
    void checkAndSet(int i,int j,vector<vector<char>>& board){
        if(i<0||i>=m||j<0||j>=n)
            return;
        if(board[i][j]!='O')
            return;
        board[i][j] = 'm';
        checkAndSet(i,j-1,board);
        checkAndSet(i,j+1,board);
        checkAndSet(i-1,j,board);
        checkAndSet(i+1,j,board);
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m<3)
            return;
        n = board[0].size();
        if(n<3)
            return;
        for(int i = 0;i<m;i++){
            if(board[i][0] == 'O')
                checkAndSet(i,0,board);
            if(board[i][n-1] == 'O')
                checkAndSet(i,n-1,board);
        }
        for(int j = 1;j<n-1;j++){
            if(board[0][j] == 'O')
                checkAndSet(0,j,board);
            if(board[m-1][j] == 'O')
                checkAndSet(m-1,j,board);
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'm')
                    board[i][j] = 'O';
            }
        }
    }
};