struct Output {
	bool solvable;
	vector<vector<vector<int>>> solution;
};

class TowerPuzzleSolver {
public:
	void solveTower(vector<vector<int>>& board, vector<vector<int>>& towerValues);
	Output getOutput();

private:
	vector<vector<int>> rows, columns;
	Output output;

	bool fill(vector<vector<int>>& board, int x, int y, vector<vector<int>>& towerValues);
	bool traverse(vector<vector<int>>& board, vector<vector<int>>& towerValues);
	//bool check(vector<int>& towers, int visible);
};