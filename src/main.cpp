#include "colors.h"
#include "drop.h"
#include "game.h"
#include <raylib.h>

int main() {
    InitWindow(600, 820, "Tetrica");
    SetTargetFPS(75);

    Game game = Game();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkBlue);
        game.HandleInput();
        if (BlockDrop(0.8)) {
            game.MoveDown();
        }
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
