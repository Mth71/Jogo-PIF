#include <stdio.h> 
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

//criação dos bots
typedef struct Bot{
    Rectangle carro_bot;
    float velocidade;
    Color cor;
}bot;

bot criarBot(){
    bot b;
    b.carro_bot=(Rectangle){55+ rand()%635,-100,60,100};
    b.velocidade=2.0f +(rand()%3);
    b.cor=(Color){rand() % 255,rand() % 255,rand() % 255, 255};
    return b;

}

int main(){
    
    InitWindow(800, 600, "jogo");
    SetTargetFPS(60);
    srand(time(NULL));
    
    //carro do jogador
    Rectangle carro = {370, 500, 60,100};
    
    float offset = 0;


    bot bots[3];
    bots[0]=criarBot();
    bots[1]=criarBot();
    bots[2]=criarBot();


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

        //movimentação bots
        for(int i=0; i<3;i++){
            bots[i].carro_bot.y += bots[i].velocidade;
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
        
        //desenho dos bots
        for(int i =0;i<3;i++){
            DrawRectangleRec(bots[i].carro_bot, bots[i].cor);
        }
        
        
        
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
