#include "raylib.h"


int main(void)
{
    const int windowWidth = 1200;
    const int windowHeight = 800;

    InitWindow(windowWidth, windowHeight, "Raylib");

    SetTargetFPS(60);

    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
