#pragma once

#include "block.h"
#include "grid.h"

#include <vector>

class Game {
    public:
        Game();
        Grid grid;
        Block GetRandomBlock();
        std::vector<Block> ResetBlocks();
        void Draw();
        void HandleInput();
        void MoveLeft();
        void MoveRight();
        void MoveDown();

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        bool IsOutOfBounds();
        void RotateBlock();
};

