#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isSafe(vector<vector<char>> &board, char x,int row,int col,int m,int n){
        for (int i=0;i<n;i++){
            if (board[row][i] == x){
                return false;
            }
        }
        for (int i=0;i<m;i++){
            if (board[i][col] == x){
                return false;
            }
        }
        
        int r = row - (row%3);
        int c = col - (col%3);
        
        for (int i=r;i<=r+2;i++){
            for (int j=c;j<=c+2;j++){
                if (board[i][j] == x){
                    return false;
                }
            }
        }
        return true;
    }
    
    void printSudoku(vector<vector<char>> &board){
        for (auto &v : board){
            for (auto c : v){
                cout << c << " ";
            }
            cout << "\n";
        }
        cout << "\n\n\n";
    }
    
    bool findUnassigned(int &row,int &col,vector<vector<char>> &board){
        for (row=0;row<9;row++){
            for (col=0;col<9;col++){
                if (board[row][col] == '.'){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool helper(vector<vector<char>> &board){
        int row,col;
        if (!findUnassigned(row,col,board)) {
            return true;
        }
        
        for (int i=1;i<=9;i++){
            if (isSafe(board, i+'0', row, col, 9, 9)){
                board[row][col] = i + '0';
                if (helper(board)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};
