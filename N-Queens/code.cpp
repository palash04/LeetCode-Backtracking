#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> res;

bool canBePlaced(vector<vector<char>> &board,int row,int col,int n){
    
    for (int i=row-1;i>=0;i--){
        if (board[i][col] == 'Q'){
            return false;
        }
    }
    int i=row-1;
    int j=col-1;
    while (i>=0 && j>=0){
        if (board[i][j] == 'Q'){
            return false;
        }
        i--;
        j--;
    }
    i = row-1;
    j = col+1;
    while (i>=0 && j<=n-1){
        if (board[i][j] == 'Q'){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void printSolution(vector<vector<char>> &board,int n){
    vector<string> v;
    
    for (int i=0;i<n;i++){
        string s = "";
        for (int j=0;j<n;j++){
            s += board[i][j];
        }
        v.push_back(s);
    }
    res.push_back(v);
}

bool solveNQueensUtility(vector<vector<char>> &board,int row,int n){
    
    for (int col=0;col<n;col++){
        if (canBePlaced(board, row, col, n)){
            board[row][col] = 'Q';
            if (row == n-1) printSolution(board,n);
            if (!solveNQueensUtility(board, row+1, n)){
                board[row][col] = '.';
            }
        }
    }
    return false;
}

void solveNQueens(int n){
    vector<vector<char>> board;
    board.resize(n, vector<char>(n,'.'));
    solveNQueensUtility(board,0,n);
}

int main(){
    
    int n = 4;
    solveNQueens(n);
    for (auto v:res){
        for (auto s:v){
            cout << s << "\n";
        }
        cout << "\n\n";
    }
    cout << "\n";
}
