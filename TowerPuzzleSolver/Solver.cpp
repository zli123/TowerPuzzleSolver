#include <iostream>
#include <vector>

using namespace std;

#include "Solver.h"

void TowerPuzzleSolver::solveTower(vector<vector<int>>& board, vector<vector<int>>& towerValues) {
	//initializing the flags
	//rows stands for the unique numbers that have been assigned per row.
	//columns stands for the unique numbers that have been assigned per column.
	
	//once the unique number gets assigned, that number gets flagged as 1, and no more
	//of the same number may get assigned within the same row and column.
	rows = vector<vector<int>>(board.size(), vector<int>(board.size() + 1));
	columns = vector<vector<int>>(board.size(), vector<int>(board.size() + 1));

	//DFS + Backtrack function. Starting from the bottom left.
	output.solvable = fill(board, 0, 0, towerValues);
}

bool TowerPuzzleSolver::fill(vector<vector<int>>& board, int x, int y, vector<vector<int>>& towerValues) {
	//base case: all squares filled, check to see if the solution works.
	if (y == board.size()) {
		return traverse(board, towerValues);
	}

	//the function goes from the bottom left corner and starts assigning numbers going to the right
	//and then moves up when the last element within the row has been reached.
	int new_x = (x + 1) % board.size();
	int new_y = (new_x == 0) ? y + 1 : y;
	
	//flag assignment
	for (int i = 1; i <= int(board.size()); i++) {
		if (!rows[x][i] && !columns[y][i]) {
			rows[x][i] = 1;
			columns[y][i] = 1;
			board[x][y] = i;

			//calls next step
			if (fill(board, new_x, new_y, towerValues)) {
				//solution found
				return true;
			}
			//previous assignment incorrect. Backtrack.
			board[x][y] = 0;
			columns[y][i] = 0;
			rows[x][i] = 0;
		}
	}
	return false;
}

bool TowerPuzzleSolver::traverse(vector<vector<int>>& board, vector<vector<int>>& towerValues) {

	//check to see if the number of towers visible is the same as the number specified in towerValues

	//left to right
	for (int i = 0; i < int(towerValues[0].size()); i++) {
		int counter = 1;
		int prev = board[i][0];
		for (int j = 1; j < int(board.size()); j++) {
			if (board[i][j] > prev) {
				counter += 1;
				prev = board[i][j];
			}
		}
		if (counter != towerValues[0][i]) {
			return false;
		}
	}

	//right to left
	for (int i = 0; i < int(towerValues[1].size()); i++) {
		int counter = 1;
		int prev = board[i][board.size() - 1];
		for (int j = board.size() - 2; j >= 0; j--) {
			if (board[i][j] > prev) {
				counter += 1;
				prev = board[i][j];
			}
		}
		if (counter != towerValues[1][i]) {
			return false;
		}
	}

	//bottom to top
	for (int i = 0; i < int(towerValues[2].size()); i++) {
		int counter = 1;
		int prev = board[0][i];
		for (int j = 1; j < int(board.size()); j++) {
			if (board[j][i] > prev) {
				counter += 1;
				prev = board[j][i];
			}
		}
		if (counter != towerValues[2][i]) {
			return false;
		}
	}

	//top to bottom
	for (int i = 0; i < int(towerValues[3].size()); i++) {
		int counter = 1;
		int prev = board[board.size() - 1][i];
		for (int j = board.size() - 2; j >= 0; j--) {
			if (board[j][i] > prev) {
				counter += 1;
				prev = board[j][i];
			}
		}
		if (counter != towerValues[3][i]) {
			return false;
		}
	}
	output.solution.push_back(board);
	return true;
}

Output TowerPuzzleSolver::getOutput() {
	return output;
}