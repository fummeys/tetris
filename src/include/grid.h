#pragma once
#include <vector>
#include <raylib.h>

class Grid {
  public:
    Grid();
    int grid[20][10];
    void InitGrid();
    void PrintGrid();
    void Draw();

  private:
    int numRows;
    int numCols;
    int cellsize;
    std::vector<Color> colors;
};
