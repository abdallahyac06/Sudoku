#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sudoku.h"

int nbDigits(int n) {
	int count = 0;
	do {
		n /= 10;
		count++;
	} while (n);
	return count;
}

void initGrid(int M[][SIZE], int size, int subR, int subC, int locked[][2]) {
	srand(static_cast<unsigned>(time(0)));
	int r, c, x;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			M[i][j] = 0;
		}
	}

	for (int i = 0; i < INIT_POSTIONS; i++) {
		do {
			r = rand() % size;
			c = rand() % size;
		} while (M[r][c] != 0);
		do {
			x = rand() % size + 1;
			M[r][c] = x;
			locked[i][0] = r;
			locked[i][1] = c;
		} while (CheckElementsInRow(M, size, r) ||
				 CheckElementsInColumn(M, size, c) ||
				 CheckElementsInSubMatrix(M, r - r % subR, c - c % subC, subR, subC));
	}
}

void printGrid(int M[][SIZE], int subR, int subC, int size) {
	for (int r = 0; r < size; r++) {
		if (r % subR == 0 && r) {
			for (int i = 0; i < ((nbDigits(size) + 1) * size + 2 * (subR - 1) - 1); i++) {
				std::cout << '-';
			}

			std::cout << std::endl;
		}

		for (int c = 0; c < size; c++) {
			if (c % subC == 0 && c) {
				std::cout << "| ";
			}
			for (int i = 0; i < nbDigits(size) - nbDigits(M[r][c]); i++) {
				std::cout << '0';
			}
			std::cout << M[r][c] << ' ';
		}

		std::cout << std::endl;
	}
}

bool CheckElementsInRow(int M[][SIZE], int size, int targetRow) {
	if (targetRow < 0 || targetRow >= size) {
		std::cerr << "Error !" << std::endl;
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (M[targetRow][i] != 0) {
			for (int j = i + 1; j < size; j++) {
				if (M[targetRow][i] == M[targetRow][j]) {
					return true;
				}
			}
		}
	}
	return false;
}

bool CheckElementsInColumn(int M[][SIZE], int size, int targetColumn) {
	if (targetColumn < 0 || targetColumn >= size) {
		std::cerr << "Error !" << std::endl;
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (M[i][targetColumn] != 0) {
			for (int j = i + 1; j < size; j++) {
				if (M[i][targetColumn] == M[j][targetColumn]) {
					return true;
				}
			}
		}
	}
	return false;
}

bool CheckElementsInSubMatrix(int M[][SIZE], int startR, int startC, int subR, int subC) {
	int r, c;
	for (int i = startR; i < startR + subR; i++) {
		for (int j = startC; j < startC + subC; j++) {
			if (M[i][j] != 0) {
				r = i;
				c = j + 1;
				while (r < startR + subR) {
					while (c < startC + subC) {
						if (M[r][c] == M[i][j]) {
							return true;
						}
						c++;
					}
					c = startC;
					r++;
				}
			}
		}
	}
	return false;
}

bool isLocked(int locked[][2], int n, int row, int col) {
	for (int i = 0; i < n; i++) {
		if (locked[i][0] == row && locked[i][1] == col) {
			return true;
		}
	}
	return false;
}

bool isFull(int M[][SIZE], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (M[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}