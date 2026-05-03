#include <stdio.h> 
#include "raylib.h"

int main(){
    
    InitWindow(800, 600, "jogo");
    SetTargetFPS(60);

    Rectangle carro = {370, 500, 60,100};

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(DARKGRAY);
        
        if (IsKeyDown(KEY_RIGHT)){
            carro.x += 5;
        }
        if(IsKeyDown(KEY_LEFT)){
            carro.x -= 5;
        }
        if(IsKeyDown(KEY_UP)){
            carro.y -= 5;
        }
        if(IsKeyDown(KEY_DOWN)){
            carro.y += 5;
        }

        DrawRectangleRec(carro, RED);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
