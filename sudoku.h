#ifndef sudoku_h
#define sudoku_h

/**
 * @brief Number of columns in a sub-grid.
 */
const int SUB_COL = 2;

/**
 * @brief Number of rows in a sub-grid.
 */
const int SUB_ROW = 3;

/**
 * @brief Size of the Sudoku grid (number of rows/columns).
 */
const int SIZE = SUB_ROW * SUB_COL;

/**
 * @brief Number of initial positions to be filled in the Sudoku grid.
 */
const int INIT_POSTIONS = 5;

/**
 * @brief Calculates the number of digits in an integer.
 * 
 * @param n The integer to calculate the number of digits for.
 * @return The number of digits in the integer.
 */
int nbDigits(int n);

/**
 * @brief Initializes the Sudoku grid with given locked positions.
 * 
 * @param M The Sudoku grid to initialize.
 * @param size The size of the Sudoku grid.
 * @param subR The number of rows in a sub-grid.
 * @param subC The number of columns in a sub-grid.
 * @param locked The array of locked positions.
 */
void initGrid(int M[][SIZE], int size, int subR, int subC, int locked[][2]);

/**
 * @brief Prints the Sudoku grid.
 * 
 * @param M The Sudoku grid to print.
 * @param subR The number of rows in a sub-grid.
 * @param subC The number of columns in a sub-grid.
 * @param size The size of the Sudoku grid.
 */
void printGrid(int M[][SIZE], int subR, int subC, int size);

/**
 * @brief Checks if all elements in a row are unique.
 * 
 * @param M The Sudoku grid.
 * @param size The size of the Sudoku grid.
 * @param row The row to check.
 * @return True if all elements in the row are unique, false otherwise.
 */
bool CheckElementsInRow(int M[][SIZE], int size, int row);

/**
 * @brief Checks if all elements in a column are unique.
 * 
 * @param M The Sudoku grid.
 * @param size The size of the Sudoku grid.
 * @param column The column to check.
 * @return True if all elements in the column are unique, false otherwise.
 */
bool CheckElementsInColumn(int M[][SIZE], int size, int column);

/**
 * @brief Checks if all elements in a sub-grid are unique.
 * 
 * @param M The Sudoku grid.
 * @param startR The starting row of the sub-grid.
 * @param startC The starting column of the sub-grid.
 * @param subR The number of rows in the sub-grid.
 * @param subC The number of columns in the sub-grid.
 * @return True if all elements in the sub-grid are unique, false otherwise.
 */
bool CheckElementsInSubMatrix(int M[][SIZE], int startR, int startC, int subR, int subC);

/**
 * @brief Checks if a position in the grid is locked.
 * 
 * @param locked The array of locked positions.
 * @param n The number of locked positions.
 * @param row The row of the position to check.
 * @param col The column of the position to check.
 * @return True if the position is locked, false otherwise.
 */
bool isLocked(int locked[][2], int n, int row, int col);

/**
 * @brief Checks if the Sudoku grid is full.
 * 
 * @param M The Sudoku grid.
 * @param size The size of the Sudoku grid.
 * @return True if the grid is full, false otherwise.
 */
bool isFull(int M[][SIZE], int size);

#endif