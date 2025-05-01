#include "circle.h"
#include "square.h"
#include "raylib.h"
#include "raymath.h"    // math functions
#include "editor.h"     // editor class

#include "resource_dir.h"    // utility header for SearchAndSetResourceDir
#include <vector>

int main()
{
    const int screenWidth = 1600;
    const int screenHeight = 900;

    // Tell the window to use vsync and work on high DPI displays
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    // Create the window and OpenGL context
    InitWindow(screenWidth, screenHeight, "Shape Editor");

    // Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
    SearchAndSetResourceDir("resources");

    Editor editor;

    // game loop
    while (!WindowShouldClose())        // run the loop untill the user presses ESCAPE or presses the Close button on the window
    {
        // Update the editor
        editor.Update();

        // drawing
        BeginDrawing();

        // Setup the back buffer for drawing (clear color and depth buffers)
        ClearBackground(BLACK);

        // Draw all shapes
        editor.Draw();

        EndDrawing();
    }

    // destroy the window and cleanup the OpenGL context
    CloseWindow();
    return 0;
}
