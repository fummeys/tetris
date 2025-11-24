#include "block.h"
#include "position.h"

LBlock::LBlock() : Block() {
    id = 1;
    orientation[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
    orientation[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
    orientation[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
    orientation[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
    Move(0,3);
};

JBlock::JBlock() : Block() {
    id = 2;
    orientation[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
    orientation[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
    orientation[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
    orientation[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
    Move(0,3);
}

IBlock::IBlock() : Block() {
    id = 3;
    orientation[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
    orientation[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
    orientation[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
    orientation[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
    Move(-1,3);
}

OBlock::OBlock() : Block() {
    id = 4;
    orientation[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    Move(0,4);
}

SBlock::SBlock() : Block() {
    id = 5;
    orientation[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
    orientation[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
    orientation[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
    orientation[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
    Move(0,3);
}

TBlock::TBlock() : Block() {
    id = 6;
    orientation[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
    orientation[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
    orientation[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
    orientation[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
    Move(0,3);
}

ZBlock::ZBlock() : Block() {
    id = 7;
    orientation[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
    orientation[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
    orientation[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
    orientation[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
    Move(0,3);
}
