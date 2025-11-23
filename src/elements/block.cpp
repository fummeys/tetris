#include "block.h"
#include "colors.h"

Block::Block(){
    cellSize = 40;
    rotationState = 0;
    colors = GetCellColors();
}

void Block::Draw(){
    std::vector<Position> tiles = cells[rotationState];
    for(Position item: tiles){
        DrawRectangle(item.col * cellSize, item.row * cellSize, cellSize -1, cellSize -1, colors[id]);
    }
}
