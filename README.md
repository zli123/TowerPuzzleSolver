# TowerPuzzleSolver

The visible-tower puzzle is a puzzle similar to soduku with different constraints.
Size of puzzle is n by n square grid where n can be any natural number.
The number in each grid represent the height of a tower at that location.
No 2 towers from the same row or column may have the same height.
Around the edge of the grid are the numbers of towers visible from that location, with taller towers
obstructing the view of smaller towers behind them.
The puzzle starts off with an empty grid and only have the number of towers visible per location as constraints.
The goal is to come up with the tower height at each location that satisfies the number of towers visible.

The max number of towers visible is n, minimum is 1. There may be no solutions or multiple different solutions, which all may be found.
