#pragma once
#include <vector>
#include <raylib.h>

class Grid {
  public:
    Grid();
    int grid[20][10];
    void InitGrid();
    void Draw();
    bool IsOutOfBounds(int row, int col);
    bool IsCellEmpty(int row, int col);
    int ClearFullRows();

  private:
    int numRows;
    int numCols;
    int cellsize;
    std::vector<Color> colors;
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int distance);
};
