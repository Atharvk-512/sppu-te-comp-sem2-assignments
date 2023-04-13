// Atharv Kulkarni

// N-Queens problem solution using backtracking

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for(int i=0; i<row; i++) {
        if(board[i][col] == 1)
            return false;
    }
    
    for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if(board[i][j] == 1)
            return false;
    }
    
    for(int i=row, j=col; i>=0 && j<N; i--, j++) {
        if(board[i][j] == 1)
            return false;
    }
    
    return true;
}

void solveNQueens(vector<vector<int>>& board, int row, int N, vector<vector<vector<int>>>& solutions) {
    if(row == N){
        solutions.push_back(board);
        return;
    }
    
    for(int col=0; col<N; col++){
        if(isSafe(board, row, col, N)){
            board[row][col] = 1;
            solveNQueens(board, row+1, N, solutions);
            board[row][col] = 0;
        }
    }
}


void print_sol(vector<vector<vector<int>>>& solutions){
    if(!solutions.size()){
        cout<<"No feasible solutions for given value of N\n\n";
        return;
    }


    cout<<"No of possible solutions: "<<solutions.size()<<"\n";
    for(auto sol : solutions){
        for(auto row : sol){
            for(auto cell : row){
                cout<<cell<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
    }
    cout<<"\n";
}


int main(){
    cout<<"N Queens Problem Solution using  \n **** Backtracking ****\n";

    int N;
    cout<<"Enter number of queens: ";
    cin>>N;
    cout<<"\n";
    
    vector<vector<vector<int>>> solutions;
    vector<vector<int>> board(N, vector<int>(N, 0));
    
    solveNQueens(board, 0, N, solutions);

    print_sol(solutions);
    
    return 0;
}