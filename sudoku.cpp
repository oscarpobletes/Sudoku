//by Óscar Poblete Sáenz
#include <iostream> 
using namespace std;  

#define SIZE 9  // Defining the size of the Sudoku grid
#define EMPTY 0  // Defining the value for an empty cell

int sudoku[SIZE][SIZE];  // Declaring the Sudoku grid

// Function to find an empty cell in the Sudoku grid
bool findEmptyCell(int& row, int& col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (sudoku[row][col] == EMPTY) {
                return true;  // Found an empty cell
            }
        }
    }
    return false;  // No empty cell found
}

// Function to check if a number can be placed in a particular cell
bool canPlace(int row, int col, int num) {
    int i, j;

    // Check row
    for (j = 0; j < SIZE; j++) {
        if (sudoku[row][j] == num) {
            return false;  // Number already exists in the row
        }
    }

    // Check column
    for (i = 0; i < SIZE; i++) {
        if (sudoku[i][col] == num) {
            return false;  // Number already exists in the column
        }
    }

    // Check subgrid
    int startRow = (row / 3) * 3;  // Starting row index of the subgrid
    int startCol = (col / 3) * 3;  // Starting column index of the subgrid
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (sudoku[startRow + i][startCol + j] == num) {
                return false;  // Number already exists in the subgrid
            }
        }
    }

    return true;  // Number can be placed in the cell
}

// Function to print the Sudoku grid
void printSudoku() {
    int i, j;

    cout << "SOLUTION:\n";
    cout << "=========\n\n";
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            cout << sudoku[i][j];  // Print the cell value

            if (j == 2 || j == 5) {
                cout << " | ";  // Print horizontal separator for subgrids
            }
        }
        cout << "\n";

        if (i == 2 || i == 5) {
            cout << "--- | --- | ---\n";  // Print horizontal separator for subgrids
        }
    }
    cout << "\n";
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku() {
    int row, col, num;

    if (!findEmptyCell(row, col)) {
        return true;  // Sudoku solved, no empty cell remaining
    }

    for (num = 1; num <= SIZE; num++) {
        if (canPlace(row, col, num)) {
            sudoku[row][col] = num;  // Place the number in the cell

            if (solveSudoku()) {
                return true;  // Solution found
            }

            sudoku[row][col] = EMPTY;  // Undo the choice and backtrack
        }
    }

    return false;  // No solution found
}

// Function to read the Sudoku grid from the user
void readSudoku() {
    int i, j;

    cout << "Enter the Sudoku grid:\n";
    for (i = 0; i < SIZE; i++) {
        cout << "Row " << i + 1 << ":\n------------\n";
        for (j = 0; j < SIZE; j++) {
            cout << "Value " << j + 1 << ": ";
            cin >> sudoku[i][j];  // Read the cell value from the user
        }
    }
    cout << "\n";
}

int main() {
    readSudoku();  // Read the Sudoku grid from the user

    if (solveSudoku()) {
        printSudoku();  // If Sudoku solved, print the solution
    } else {
        cout << "No solution found for the given Sudoku puzzle.\n";
    }

    return 0;
}
