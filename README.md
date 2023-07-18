# Sudoku Solver

Sudoku solver implemented in C++. The program allows users to enter a Sudoku puzzle and solves it using a backtracking algorithm.

## How to Use

1. The Sudoku puzzle is represented as a 9x9 grid, where each cell contains a number from 1 to 9.
2. The program prompts the user to enter the Sudoku grid row by row.
3. For each row, the program prompts the user to enter the value for each cell.
4. Enter the value of each cell, and if the cell is empty, enter 0 (zero).
5. After entering the entire Sudoku grid, the program attempts to solve the puzzle.
6. If a solution is found, the program prints the solved Sudoku grid.
7. If no solution is found, the program displays a message indicating that no solution was found for the given puzzle.

## Implementation Details

The program is implemented in C++ and consists of the following functions:

- **findEmptyCell**: Finds the next empty cell in the Sudoku grid.
- **canPlace**: Checks if a number can be placed in a particular cell based on the Sudoku rules (no duplicates in rows, columns, and subgrids).
- **printSudoku**: Prints the Sudoku grid, representing the solved puzzle.
- **solveSudoku**: Solves the Sudoku puzzle using a backtracking algorithm.
- **readSudoku**: Reads the Sudoku grid from the user.
- **main**: The main function that controls the flow of the program. It reads the Sudoku grid from the user, solves the puzzle, and prints the solution if found.

## Example

An example Sudoku grid:

```cpp
int sudoku[SIZE][SIZE] = {
    { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
};
```
This example Sudoku grid can be used to test the program. Simply replace the readSudoku function call in the main function with the provided example grid.

## Compilation and Execution

To compile the program, save the code into a file named `sudoku.cpp` and use a C++ compiler to compile it, for example:

`g++ sudoku.cpp -o sudoku`

To run the compiled program, execute the following command:

`./sudoku`

Follow the prompts on the screen to enter the Sudoku puzzle and see the solution if found.

Enjoy solving Sudoku puzzles!
