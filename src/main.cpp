#include "colors.h"
#include "game.h"
#include <raylib.h>

int main() {
    InitWindow(400, 800, "Tetrica");
    SetTargetFPS(75);

    Game game = Game();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
