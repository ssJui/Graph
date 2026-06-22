#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printSolutions(const vector<vector<string>>& solutions) {
    if (solutions.empty()) {
        cout << "No solutions found." << endl;
        return;
    }
    
    cout << "\nFound " << solutions.size() << " distinct solutions!\n" << endl;
    
    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Solution " << i + 1 << ":" << endl;
        for (const string& row : solutions[i]) {
            cout << row << endl;
        }
        cout << "----------------" << endl;
    }
}

void solveNQueensHelper(int row, int n, vector<string>& board, vector<vector<string>>& result,
                        vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
                            
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; ++col) {
        
        int d1 = row - col + n - 1; 
        int d2 = row + col;         
        
        if (cols[col] == false && diag1[d1] == false && diag2[d2] == false) {
            
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            
            solveNQueensHelper(row + 1, n, board, result, cols, diag1, diag2);
            
            board[row][col] = '.';
            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    
    vector<string> board(n, string(n, '.'));
    
    vector<bool> cols(n, false);          
    vector<bool> diag1(2 * n - 1, false); 
    vector<bool> diag2(2 * n - 1, false); 
    
    solveNQueensHelper(0, n, board, result, cols, diag1, diag2);
    
    return result;
}

int main() {
    int n;
    
    cout << "Enter the size of the board (for example, 4): ";
    cin >> n;
    
    vector<vector<string>> solutions = solveNQueens(n);
    
    printSolutions(solutions);
    
    return 0;
}