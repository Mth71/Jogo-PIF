#include <stdio.h>
#include <raylib.h>

typedef enum
{
    MENU,
    JOGO,
    CONFIG,
    TOP10
} GameScreen;


int main(void) {

    const int screenWhidth = 1280;
    const int sreenHeight = 720;

    InitWindow(screenWhidth, sreenHeight, "Retro Race");

    SetTargetFPS(60);

    Texture2D menuBackground = LoadTexture("assets/menu.png");

    GameScreen telaAtual = MENU;

    Rectangle botaoIniciar = {400, 355, 480, 85};
    Rectangle botaoConfig  = {400, 455, 480, 85};
    Rectangle botaoTop10   = {400, 555, 480, 85};

    while (!WindowShouldClose()){
        
        Vector2 mouse = GetMousePosition();

        if(telaAtual == MENU){

            bool hoverIniciar = 
                CheckCollisionPointRec(mouse, botaoIniciar);
            
            bool hoverConfig =
                CheckCollisionPointRec(mouse, botaoConfig);

            bool hoverTop10 =
                CheckCollisionPointRec(mouse, botaoTop10);


            if(hoverIniciar && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){

                telaAtual == JOGO;

            }
            if(hoverConfig && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){

                telaAtual = CONFIG;
            }
            if(hoverTop10 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                
                telaAtual = TOP10;
            }

            BeginDrawing();

            ClearBackground(BLACK);

            DrawTexture(menuBackground, 0, 0, WHITE);

            if(hoverIniciar){

                DrawRectangleLinesEx(botaoIniciar, 4, GREEN);
            }

            if(hoverConfig){

                DrawRectangleLinesEx(botaoConfig, 4, SKYBLUE);
            }

            if(hoverTop10){

                DrawRectangleLinesEx(botaoTop10, 4, YELLOW);
            }
            
            EndDrawing();

        }



    }
    

    
}