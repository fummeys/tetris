#pragma once
#include "position.h"
#include "raylib.h"
#include <map>
#include <vector>

class Block {
    public:
        Block();
        int id;
        std::map<int, std::vector<Position>> orientation;
        void Draw(int offsetx, int offsety);
        void Move(int rows, int cols);
        std::vector<Position> GetCellPositions();
        void Rotate();
        void UndoRotation();

    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;
        int rowOffset;
        int colOffset;
};

class LBlock : public Block {
    public:
        LBlock();
};

class JBlock : public Block {
    public:
        JBlock();
};

class IBlock : public Block {
    public:
        IBlock();
};

class OBlock : public Block {
    public:
        OBlock();
};

class SBlock : public Block {
    public:
        SBlock();
};

class TBlock : public Block {
    public:
        TBlock();
};

class ZBlock : public Block {
    public:
        ZBlock();
};
