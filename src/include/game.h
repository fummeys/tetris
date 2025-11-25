#pragma once

#include "block.h"
#include "grid.h"
#include "raylib.h"

#include <vector>

class Game {
    public:
        Game();
        ~Game();
        bool gameOver;
        int score;
        Music music;
        bool isPaused;
        void Draw();
        void HandleInput();
        void MoveDown();

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Grid grid;
        Sound rotateSound;
        Sound clearSound;
        Sound dropSound;

        void DropBlock();
        Block GetRandomBlock();
        std::vector<Block> ResetBlocks();
        void MoveLeft();
        void MoveRight();
        bool IsOutOfBounds();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void ResetGame();
        void UpdateScore(int linescleared, int movepoint);
        void TogglePause();
};
