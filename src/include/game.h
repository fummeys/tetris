#pragma once

#include "block.h"
#include "grid.h"

#include <vector>

class Game {
    public:
        Game();
        Grid grid;
        bool gameOver;
        Block GetRandomBlock();
        std::vector<Block> ResetBlocks();
        void Draw();
        void HandleInput();
        void MoveLeft();
        void MoveRight();
        void MoveDown();
        void DropBlock();

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        bool IsOutOfBounds();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void ResetGame();
};

