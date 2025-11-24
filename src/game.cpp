#include "game.h"
#include "position.h"

#include <raylib.h>
#include <stdlib.h>
#include <vector>

Game::Game() {
    grid = Grid();
    blocks = ResetBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
}

Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = ResetBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);

    return block;
}

std::vector<Block> Game::ResetBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(),
        SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput() {
    int keypressed = GetKeyPressed();

    if (gameOver && keypressed == KEY_ENTER) {
        ResetGame();
    }

    switch (keypressed) {
        case KEY_LEFT:
            MoveLeft();
            break;
        case KEY_RIGHT:
            MoveRight();
            break;
        case KEY_DOWN:
            MoveDown();
            break;
        case KEY_ENTER:
            DropBlock();
            break;
        case KEY_UP:
            RotateBlock();
            break;
    }
}

void Game::MoveLeft() {
    if (gameOver)
        return;
    currentBlock.Move(0, -1);
    if (IsOutOfBounds() || BlockFits() == false) {
        currentBlock.Move(0, 1);
    }
}

void Game::MoveRight() {
    if (gameOver)
        return;
    currentBlock.Move(0, 1);
    if (IsOutOfBounds() || BlockFits() == false) {
        currentBlock.Move(0, -1);
    }
}

void Game::MoveDown() {

    if (gameOver)
        return;
    currentBlock.Move(1, 0);
    if (IsOutOfBounds() || BlockFits() == false) {
        currentBlock.Move(-1, 0);
        LockBlock();
    }
}

void Game::DropBlock() {
    if (gameOver)
        return;
    while (true) {
        currentBlock.Move(1, 0);
        if (IsOutOfBounds() || BlockFits() == false) {
            currentBlock.Move(-1, 0);
            LockBlock();
            break;
        }
    }
}

bool Game::IsOutOfBounds() {
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles) {
        if (grid.IsOutOfBounds(item.row, item.col)) {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock() {
    if (gameOver) return;
    currentBlock.Rotate();
    if (IsOutOfBounds()) {
        currentBlock.UndoRotation();
    }
}

void Game::LockBlock() {
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles) {
        grid.grid[item.row][item.col] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if (BlockFits() == false) {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    grid.ClearFullRows();
}

bool Game::BlockFits() {
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles) {
        if (grid.IsCellEmpty(item.row, item.col) == false) {
            return false;
        }
    }
    return true;
}

void Game::ResetGame() {
    grid.InitGrid();
    blocks = ResetBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
}
