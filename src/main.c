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

    const screenWhidth = 1280;
    const sreenHeight = 720;

    InitWindow(screenWhidth, sreenHeight, "Retro Race");

    SetTargetFPS(60);

    Texture2D manuBackground = LoadTexture("assets/menu.png");

    GameScreen telaAtual = MENU;

    Rectangle botaoIniciar = {365, 355, 550, 85};
    Rectangle botaoConfig  = {365, 470, 550, 85};
    Rectangle botaoTop10   = {365, 585, 550, 85};

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
            

        }

    }
    

    
}