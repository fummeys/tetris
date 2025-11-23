#include "grid.h"
#include <raylib.h>
#include "elements/blocks.cpp"
#include "colors.h"

int main() {
    InitWindow(400, 800, "Tetrica");
    SetTargetFPS(75);

    Grid grid = Grid();

    LBlock block = LBlock();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
