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
    score = 0;
    isPaused = false;
    InitAudioDevice();
    music = LoadMusicStream("Assets/Sounds/music.mp3");
    rotateSound = LoadSound("Assets/Sounds/rotate.wav");
    clearSound = LoadSound("Assets/Sounds/clear.wav");
    dropSound = LoadSound("Assets/Sounds/drop.wav");
    PlayMusicStream(music);
}

Game::~Game() {
    UnloadMusicStream(music);
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadSound(dropSound);
    CloseAudioDevice();
}

Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = ResetBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);

    UpdateScore(0, 1);
    return block;
}

std::vector<Block> Game::ResetBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(),
            SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
    grid.Draw();
    currentBlock.Draw(0, 0);
    switch (nextBlock.id) {
    case 3:
        nextBlock.Draw(300, 220);
        break;
    case 4:
        nextBlock.Draw(300, 220);
        break;
    default:
        nextBlock.Draw(320, 220);
        break;
    }
}

void Game::HandleInput() {
    int keypressed = GetKeyPressed();

    if (gameOver && keypressed == KEY_SPACE) {
        ResetGame();
        return;
    }

    if (isPaused && keypressed == KEY_SPACE) {
        TogglePause();
        return;
    }

    if (isPaused == true) {
        return;
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
            PlaySound(dropSound);
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
    if (gameOver)
        return;
    currentBlock.Rotate();
    PlaySound(rotateSound);
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
    int rowscleard = grid.ClearFullRows();
    if (rowscleard > 0) {
        PlaySound(clearSound);
        UpdateScore(rowscleard, 0);
    }
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
    score = 0;
    isPaused = false;
}

void Game::UpdateScore(int linescleared, int movepoint) {
    score += movepoint;

    switch (linescleared) {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    case 4:
        score += 500;
        break;
    default:
        break;
    }
}

void Game::TogglePause() { isPaused = !isPaused; }
