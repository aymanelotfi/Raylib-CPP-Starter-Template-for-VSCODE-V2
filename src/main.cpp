#include <raylib.h>
#include "grid.h"

int main() 
{
    const Color darkBlue = {44, 44 , 127, 255};
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;
    
    
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);
    Grid g = Grid();
    
    while (!WindowShouldClose())
    {   
        BeginDrawing();
            ClearBackground(darkBlue);
            g.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}