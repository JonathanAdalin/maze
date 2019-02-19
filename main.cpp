#include <iostream>

void PrintMaze(bool** maze, int cols, int rows) {
    for (int j = 0; j < rows; j++) {
        std::cout << std::endl;
        for (int i = 0; i < cols; i++) {
            bool current_val = maze[i][j];
            if (current_val == true)
                std::cout << "[ ] ";
            else
                std::cout << "[X] ";
        }
    }
    // Make the console look nicer.
    std::cout << std::endl << std::endl;
}

// Algorithm Helper Functions

bool LeftOK(bool** maze, int x, int y) {
    if (x - 1 >= 0)  // Don't want to access an element out of bounds.
        if (maze[x - 1][y] == true)
            return true;
    return false;
}

bool AboveOK(bool** maze, int x, int y) {
    if (y - 1 >= 0)  // Don't want to access an element out of bounds.
        if (maze[x][y - 1] == true)
            return true;
    return false;   
}

// Algorithm: Count Paths, Runtime: O(cols*rows)
// Returns the number of ways to get from the top-left corner to the
// bottom-right corner of <maze> assuming you can only go right or down.
int CountPaths(bool** maze, int cols, int rows) {
    if (!maze[0][0] || !maze[cols - 1][rows - 1])
        return 0;  // Source or Destination is unaccessible.
    int dp[cols][rows];
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			if (AboveOK(maze, i, j) && LeftOK(maze, i, j))
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			else if (AboveOK(maze, i, j))
				dp[i][j] = dp[i][j - 1];
			else if (LeftOK(maze, i, j))
				dp[i][j] = dp[i - 1][j];
            else if (i == 0 && j == 0) {
                // Source is accessible despite no left or above tiles
                dp[0][0] = 1;
            } else  // This tile is unaccessible.
				dp[i][j] = 0;
		}
	}
	return dp[cols-1][rows-1];
}

int main() {

    int cols = 4;
    int rows = 3;

    bool** maze = new bool*[cols];
    for (int i = 0; i < cols; i++)
        maze[i] = new bool[rows];

    // Every tile should be accessible at first.
    for (int i = 0; i < cols; i++)
        for (int j = 0; j < rows; j++)
            maze[i][j] = true;
    
    // Add maze blocks here if desired.
    maze[1][1] = false;
    maze[3][2] = false;

    PrintMaze(maze, cols, rows);
    std::cout << "Paths: " << CountPaths(maze, cols, rows)
              << std::endl << std::endl;
}

