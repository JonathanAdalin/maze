#include <iostream>

// Helper Function
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
    std::cout << std::endl;
    std::cout << std::endl;
}

// Algorithm Driver
int main() {

    int cols = 4;
    int rows = 3;

    bool** maze = new bool*[cols];
    for (int i = 0; i < cols; i++)
        maze[i] = new bool[rows];

    for (int i = 0; i < cols; i++)
        for (int j = 0; j < rows; j++)
            maze[i][j] = true;
    maze[2][1] = false;

    PrintMaze(maze, cols, rows);
}

