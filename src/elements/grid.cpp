#include "grid.h"
#include "colors.h"

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellsize = 40;
    InitGrid();
    colors = GetCellColors();
}

void Grid::InitGrid() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            grid[row][col] = 0;
        }
    }
}

void Grid::Draw() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int cellvalue = grid[row][col];
            DrawRectangle(col * cellsize, row * cellsize, cellsize - 1,
                          cellsize - 1, colors[cellvalue]);
        }
    }
}

bool Grid::IsOutOfBounds(int row, int col) {
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        return true;
    }
    return false;
}

bool Grid::IsCellEmpty(int row, int col) {
    if (grid[row][col] == 0) {
        return true;
    }
    return false;
};

bool Grid::IsRowFull(int row) {
    for (int col = 0; col < numCols; col++) {
        if (grid[row][col] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row) {
    for (int col = 0; col < numCols; col++) {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int distance) {
    for (int col = 0; col < numCols; col++) {
        grid[row + distance][col] = grid[row][col];
        grid[row][col] = 0;
    }
}

int Grid::ClearFullRows(){
    int completed = 0;
    for(int row = numRows -1; row >= 0; row--){
        if(IsRowFull(row)){
            ClearRow(row);
            completed++;
        } else if(completed > 0){
            MoveRowDown(row, completed);
        }
    }

    return completed;
}
