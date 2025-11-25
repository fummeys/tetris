#include "block.h"
#include "colors.h"

Block::Block() {
    cellSize = 40;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw(int offsetx, int offsety) {
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles) {
        DrawRectangle((item.col * cellSize) + offsetx,
                      (item.row * cellSize) + offsety, cellSize - 1,
                      cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int cols) {
    rowOffset += rows;
    colOffset += cols;
}

std::vector<Position> Block::GetCellPositions() {
    std::vector<Position> tiles = orientation[rotationState];
    std::vector<Position> moveTiles;
    for (Position item : tiles) {
        Position newPos = Position(item.row + rowOffset, item.col + colOffset);
        moveTiles.push_back(newPos);
    }
    return moveTiles;
}

void Block::Rotate() {
    rotationState++;
    if (rotationState == orientation.size()) {
        rotationState = 0;
    }
}

void Block::UndoRotation() {
    rotationState--;
    if (rotationState == -1) {
        rotationState = 0;
    }
}
