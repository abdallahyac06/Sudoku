#ifndef sudoku_h
#define sudoku_h

const int SUB_COL = 2;
const int SUB_ROW = 3;
const int SIZE = SUB_ROW * SUB_COL;
const int INIT_POSTIONS = 5;

int nbDigits(int n) ;
void initGrid(int M[][SIZE], int size, int subR, int subC, int locked[][2]);
void printGrid(int M[][SIZE], int subR, int subC, int size);
bool CheckElementsInRow(int M[][SIZE], int size, int row);
bool CheckElementsInColumn(int M[][SIZE], int size, int column);
bool CheckElementsInSubMatrix(int M[][SIZE], int startR, int startC, int subR, int subC);
bool isLocked(int locked[][2], int n, int row, int col);
bool isFull(int M[][SIZE], int size);

#endif