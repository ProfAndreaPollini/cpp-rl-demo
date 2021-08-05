/*******************************************************************************************
*
*   raylib-cpp [core] example - Basic window
*
*   Welcome to raylib-cpp!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib-cpp. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib-cpp is licensed under an unmodified zlib/libpng license (View raylib-cpp.hpp for details)
*
*   Copyright (c) 2021 Rob Loach (@RobLoach)
*
********************************************************************************************/

#include "raylib-cpp.hpp"

#include "constants.h"
#include "game.hpp"


int main() {
    // Initialization
    //--------------------------------------------------------------------------------------

    raylib::Color textColor = LIGHTGRAY;
    raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");

    Game::getInstance().setup();



    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose())    // Detect window close button or ESC key
        {
        // Update
        //----------------------------------------------------------------------------------
        Game::getInstance().update();
        // Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        window.ClearBackground(RAYWHITE);

        Game::getInstance().draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
        }

    return 0;
}