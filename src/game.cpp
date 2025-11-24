#include "game.h"
#include "block.h"
#include <stdlib.h>
#include <vector>

Game::Game() {
    grid = Grid();
    blocks = ResetBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
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
