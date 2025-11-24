#include "colors.h"
#include "drop.h"
#include "game.h"
#include <raylib.h>

int main() {
    InitWindow(600, 820, "Tetrica");
    SetTargetFPS(75);
    Font font = LoadFontEx("Fonts/PixelifySans-Regular.ttf", 48, 0, 0);

    Game game = Game();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkBlue);
        game.HandleInput();
        if (BlockDrop(0.8)) {
            game.MoveDown();
        }
        DrawTextEx(font, "Score", {460, 15}, 28, 2, WHITE);
        DrawRectangleRounded({420, 55, 170, 60}, 0.3, 0, lightBlue);

        DrawTextEx(font, "Next", {460, 150}, 28, 2, WHITE);
        DrawRectangleRounded({420, 185, 170, 150}, 0.3, 0, lightBlue);

        if (game.gameOver) {
            DrawTextEx(font, "Game Over", {430, 400}, 28, 2, WHITE);
        }
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
