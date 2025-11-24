#include "block.h"
#include "grid.h"
#include "colors.h"
#include <raylib.h>

int main() {
    InitWindow(400, 800, "Tetrica");
    SetTargetFPS(75);

    Grid grid = Grid();

    IBlock block = IBlock();
    // block.Move(10, 3);

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
