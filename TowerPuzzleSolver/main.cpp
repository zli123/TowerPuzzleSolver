#include <iostream>
#include <vector>

using namespace std;

#include "Solver.h"


int main() {
	//set up a size 5x5 puzzle.
	//a stands for the number of towers visible from the left, down to up.
	//b stands for the number of towers visible from the right, down to up.
	//c stands for the number of towers visible from the top, left to right.
	//d stands for the number of towers visible from the bottom, left to right.
	vector<vector<int>> board(5, vector<int>(5, 0));
	vector<int> a(5, 0), b(5, 0), c(5, 0), d(5, 0);
	a[0] = 2, a[1] = 2, a[2] = 3, a[3] = 1, a[4] = 3;
	b[0] = 1, b[1] = 4, b[2] = 3, b[3] = 4, b[4] = 2;
	c[0] = 2, c[1] = 2, c[2] = 3, c[3] = 4, c[4] = 1;
	d[0] = 2, d[1] = 3, d[2] = 2, d[3] = 1, d[4] = 2;
	vector<vector<int>> towerValues{ a, b, c, d };
	TowerPuzzleSolver solver;
	solver.solveTower(board, towerValues);
	vector<vector<vector<int>>> solutions = solver.getOutput().solution;
	bool success = solver.getOutput().solvable;
	cout << success << endl;

	//prints out the solution to the puzzle.
	for (int i = 0; i < int(solutions.size()); i++) {
		for (int j = int(solutions[i].size() - 1); j >= 0; j--) {
			for (int k = 0; k < int(solutions[i][j].size()); k++) {
				cout << solutions[i][j][k];
			}
			cout << endl;
		}
	}
	return 0;

}