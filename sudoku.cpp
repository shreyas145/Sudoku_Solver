class Solution {
public:
    char value[9] = {'1','2','3','4','5','6','7','8','9'};
    bool valid(int row, int col, char n, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){//check row
            if(board[row][i]==n) return false;
        }
        for(int i = 0; i < 9; i++){//check col
            if(board[i][col]==n) return false;
        }
        int maxrow, maxcol;
        for(int i = 3; i <= 9; i+=3) if(i>row){
            maxrow = i;
            break;
        }
        for(int i = 3; i <= 9; i+=3) if(i>col){
            maxcol = i;
            break;
        }
        for(int i = maxrow-3; i<maxrow; i++){
            for(int j = maxcol-3; j<maxcol; j++){
                if(board[i][j]==n) return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j]!='.') continue;
                for(int n = 0; n < 9; n++){
                    if(valid(i,j,value[n],board)){
                        board[i][j]=value[n];
                        if(!solve(board)) board[i][j]='.';
                        else return true;
                    }
                }
                if(board[i][j]=='.') return false;
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
