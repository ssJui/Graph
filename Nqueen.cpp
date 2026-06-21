#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- HELPER FUNCTION: Prints the boards nicely ---
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

// --- THE CORE LOGIC: Backtracking Function ---
void solveNQueensHelper(int row, int n, vector<string>& board, vector<vector<string>>& result,
                        vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
                            
    // BASE CASE: If we reached the end (row == n), we placed all queens successfully!
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    // Try placing a queen in every column of the current row
    for (int col = 0; col < n; ++col) {
        
        // Calculate the "ID" for the current square's diagonals
        int d1 = row - col + n - 1; // Left-to-right diagonal (\)
        int d2 = row + col;         // Right-to-left diagonal (/)
        
        // Check if the current spot is safe (no queens in the same column or diagonals)
        if (cols[col] == false && diag1[d1] == false && diag2[d2] == false) {
            
            // 1. PLACE THE QUEEN
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            
            // 2. MOVE TO NEXT ROW (Recursion)
            solveNQueensHelper(row + 1, n, board, result, cols, diag1, diag2);
            
            // 3. REMOVE THE QUEEN (Backtracking)
            // We undo our placement so we can try the next column in the loop
            board[row][col] = '.';
            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
}

// --- SETUP FUNCTION ---
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    
    // Create an empty n x n board filled with dots ('.')
    vector<string> board(n, string(n, '.'));
    
    // Arrays to keep track of where queens are currently placed
    vector<bool> cols(n, false);          // Tracks columns
    vector<bool> diag1(2 * n - 1, false); // Tracks \ diagonals
    vector<bool> diag2(2 * n - 1, false); // Tracks / diagonals
    
    // Start the process at row 0
    solveNQueensHelper(0, n, board, result, cols, diag1, diag2);
    
    return result;
}

// --- MAIN FUNCTION ---
int main() {
    int n;
    
    cout << "Enter the size of the board (for example, 4): ";
    cin >> n;
    
    // Call the setup function to solve the puzzle
    vector<vector<string>> solutions = solveNQueens(n);
    
    // Print the results using our helper function
    printSolutions(solutions);
    
    return 0;
}