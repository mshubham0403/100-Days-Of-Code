#include<bits/stdc++.h>
using namespace std;
   //day-62
    // MS001
 bool isPossible(string c ,int row,int col,vector<vector<string>>&board){
             for(int i=0;i<9;i++){
                // cout<<"check rows" <<board[row][i]<<"with"<<c<<endl;
                    
                     if(board[i][col]==c){
                         return false;
                     }
                     // cout<<"check cols" << board[i][col]<<"with"<<c<<endl;
                     if(board[row][i]==c){
                         return false;
                     }
                     int rn = (((row/3)*3)+(i/3));
                     int cn = (((col/3)*3)+(i%3));
                 // cout<<"check grids" << board[rn][cn]<<"with"<<c<<endl;
                     if(board[rn][cn]==c){
                         return false;
                     }

             }
             return true;
         }
        
        bool sudokuSolution(vector<vector<string>>&board){
            
            for(int row=0;row<9;row++){
                for(int col =0;col<9;col++){
                                                                             
                    if(board[row][col]=="."){
                       
                      
                        for(int i=1;i<=9;i++){
                            string c =to_string(i);
                            if(isPossible(c,row,col,board)){
                               
                                board[row][col]=c;
                                // cout<<endl;
                                // cout<<"tryning "<<c<<" at "<<row<<","<<col<<endl;
                                // cout<<endl;
                                bool result =sudokuSolution(board);
                                if(result){
                                    return true;
                                }
                                else{
                                    board[row][col]='.';
                                }
                                
                            }
                        }
                        // cout<<"checked all going back"<<endl;
                        return false;
                       
                      
                    }
                }
            }
          return true;
        }
    
    void completeSudoku(vector<vector<string>>& board) {
        bool ans =sudokuSolution(board);
        
    }
   int main(){

vector < vector<string> > incompleteSudoku = {
                                {"5","3",".",".","7",".",".",".","."},
                                {"6",".",".","1","9","5",".",".","."},
                                {".","9","8",".",".",".",".","6","."},
                                {"8",".",".",".","6",".",".",".","3"},
                                {"4",".",".","8",".","3",".",".","1"},
                                {"7",".",".",".","2",".",".",".","6"},
                                {".","6",".",".",".",".","2","8","."},
                                {".",".",".","4","1","9",".",".","5"},
                                {".",".",".",".","8",".",".","7","9"}
};

completeSudoku(incompleteSudoku);
for(auto &x:incompleteSudoku){
    for(auto&i:x){
        cout<<i<<" ";
    }
    cout<<endl;
}
 cout<<endl;


return 0;
}
