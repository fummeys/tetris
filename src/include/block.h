#pragma once
#include "position.h"
#include "raylib.h"
#include <map>
#include <vector>

class Block {
  public:
    Block();
    int id;
    std::map<int, std::vector<Position>> cells;
    void Draw();

  private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
};

