#include <stdio.h> 
#include "raylib.h"

int main(){
    
    InitWindow(800, 600, "jogo");
    SetTargetFPS(60);

    Rectangle carro = {370, 500, 60,100};
    float offset = 0;
    while(!WindowShouldClose()){
        offset += 5.0f;
        if(offset >= 100){
            offset = 0;
        }
        ClearBackground(DARKGRAY);
        
        //definição das teclas 
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

        //limites da pista]
        if(carro.x < 55){
            carro.x=55;
        }
        if(carro.x + carro.width > 745){
            carro.x=745-carro.width;
        }

        BeginDrawing();

        DrawRectangleRec(carro, RED);
        
        //tela com scroll
        for(int i =0; i<6;i++){
            int y = (int)(offset+i*100)%600;
            DrawRectangle(390, y, 10,60,YELLOW);
        } 
        // bordas da pista
        DrawRectangle(40,0,15,750, WHITE); // borda da esquerda
        DrawRectangle(745,0,15,750, WHITE); // borda direita
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
