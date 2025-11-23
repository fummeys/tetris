#include "grid.h"
#include "colors.h"
#include <cstdio>

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

void Grid::PrintGrid() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            std::printf(" %d", grid[row][col]);
        }
        std::printf(" \n");
    }
}

void Grid::Draw(){
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int cellvalue = grid[row][col];
            DrawRectangle(col * cellsize, row * cellsize, cellsize -1, cellsize -1, colors[cellvalue]);
        }
    }
}
