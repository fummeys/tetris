#include "colors.h"
#include "drop.h"
#include "game.h"
#include <cstdio>
#include <raylib.h>

int main() {
    InitWindow(600, 820, "Tetrica");
    SetTargetFPS(75);
    Font font = LoadFontEx("Assets/Fonts/PixelifySans-Regular.ttf", 48, 0, 0);

    Game game = Game();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkBlue);
        game.HandleInput();
        if (BlockDrop(0.8, game.isPaused)) {
            game.MoveDown();
        }

        DrawTextEx(font, "Score", {460, 15}, 28, 2, WHITE);
        DrawRectangleRounded({420, 55, 170, 60}, 0.3, 0, lightBlue);
        char scores[10];
        sprintf(scores, "%d", game.score);
        Vector2 textsize = MeasureTextEx(font, scores, 48, 2);

        DrawTextEx(font, scores, {420 + (170 - textsize.x) / 2, 75}, 28, 2,
                   WHITE);

        DrawTextEx(font, "Next", {460, 150}, 28, 2, WHITE);
        DrawRectangleRounded({420, 180, 160, 160}, 0.3, 0, lightBlue);

        if (game.gameOver) {
            DrawTextEx(font, "Game Over", {430, 400}, 28, 2, WHITE);
        }
        UpdateMusicStream(game.music);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
