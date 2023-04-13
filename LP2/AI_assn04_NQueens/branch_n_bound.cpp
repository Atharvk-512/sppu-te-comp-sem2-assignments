// Atharv Kulkarni

// N-Queens problem solution using branch and bound


#include<iostream>
#include<vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N, vector<bool>& col_a, vector<bool>& dia1_a, vector<bool>& dia2_a){
    if(col_a[col]==0 && dia1_a[row+col]==0 && dia2_a[row-col+N-1]==0)
        return true;
    
    return false;
}

void SolveN(vector<vector<int>>& board, int row, int N, vector<vector<vector<int>>>& solutions, vector<bool>& col_a, vector<bool>& dia1_a , vector<bool>& dia2_a){

    if(row==N){
        solutions.push_back(board);
        return;
    }

    for(int col=0; col<N; col++){
        if(isSafe(board, row, col, N, col_a, dia1_a, dia2_a)){
            board[row][col]=1;
            col_a[col]=1;
            dia1_a[row+col]=1;
            dia2_a[row-col+N-1]=1;

            SolveN(board, row+1, N, solutions, col_a, dia1_a, dia2_a);
            
            board[row][col]=0;
            col_a[col]=0;
            dia1_a[row+col]=0;
            dia2_a[row-col+N-1]=0;
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


int main() {
    cout<<"N Queens Problem Solution using  \n **** Branch and Bound ****\n";

    int N;
    cout<<"Enter size of chessboard (No of queens) : ";
    cin>>N;
    cout<<"\n";

    vector<vector<vector<int>>> solutions;
    vector<vector<int>> board(N, vector<int>(N, 0));

    // col_a[] - for column array
    // dia1_a[] - for diagonal 1 array
    // 0 0 0 *
    // 0 0 * 0
    // 0 * 0 0
    // * 0 0 0

    // dia2_a[] - for diagonal 2 array 
    // * 0 0 0
    // 0 * 0 0
    // 0 0 * 0
    // 0 0 0 *


    vector<bool> col_a(N,0);
    vector<bool> dia1_a(2*N-1,0);
    vector<bool> dia2_a(2*N-1,0);


    SolveN(board, 0, N, solutions, col_a, dia1_a, dia2_a);

    print_sol(solutions);    

    return 0;
}