#include <iostream>
#include "sudoku.h"

int main() {
    int grid[SIZE][SIZE];
    int locked[INIT_POSTIONS][2];
    initGrid(grid, SIZE, SUB_ROW, SUB_COL, locked);
    int row, col, x, subr, subc;
    bool quit = false;

    
    while (!quit) {
        printGrid(grid, SUB_ROW, SUB_COL, SIZE);

        while (!quit) {
            std::cout << "Enter the row (-1 to quit the game) :" << std::endl;
            std::cin >> row;
            if (row == -1) {
                quit = true;
                break;
            }
            row--;

            std::cout << "Enter the column (-1 to quit the game) :" << std::endl;
            std::cin >> col;
            if (row == -1) {
                quit = true;
                break;
            }
            col--;

            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || isLocked(locked, INIT_POSTIONS, row, col)) {
                std::cout << "Invalide cell" << std::endl;    
            } else {
                break;
            }
        }

        while(!quit) {
            std::cout << "Enter the number (-1 to quit the game) :" << std::endl;
            std::cin >> x;
            if (x == -1) {
                quit = true;
                break;
            }
            grid[row][col] = x;

            if (x < 0 || x > SUB_ROW * SUB_COL) {
                std::cout << x << " is out of range." << std::endl;
                grid[row][col] = 0;
                continue;
            }
            if (CheckElementsInRow(grid, SIZE, row)) {
                std::cout << x << " is already in the same row." << std::endl;
                grid[row][col] = 0;
                continue;
            }
            if (CheckElementsInColumn(grid, SIZE, col)) {
                std::cout << x << " is already in the same column." << std::endl;
                grid[row][col] = 0;
                continue;
            }
            subr = row - row % SUB_ROW;
            subc = col - col % SUB_COL;
            if (CheckElementsInSubMatrix(grid, subr, subc, SUB_ROW, SUB_COL)) {
                std::cout << x << " is already in the same sub matrix." << std::endl;
                grid[row][col] = 0;
                continue;
            }
            break;
        }

        if (isFull(grid, SIZE)) {
            printGrid(grid, SUB_ROW, SUB_COL, SIZE);
            std::cout << "You Won !!" << std::endl;
            quit = true;
        }
    }
    return 0;
}