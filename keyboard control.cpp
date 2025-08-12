#include <raylib.h>

int main(){
    int ballX = 400;
    int ballY = 400;
    Color green = {20, 160, 133, 255};

    InitWindow(800,800, "my first raylib game");
    SetTargetFPS(120);

    //game loop
    while(WindowShouldClose() == false){
        //event handeling
        if(IsKeyDown(KEY_RIGHT)){
            ballX += 3;
        } else if(IsKeyDown(KEY_LEFT)){
            ballX -= 3;
        } 
        if(IsKeyDown(KEY_UP)){
            ballY -= 3;
        }
        if(IsKeyDown(KEY_DOWN)){
            ballY += 3;
        }

        //updating 

        //drawing the objects
        BeginDrawing();
        ClearBackground(green);
        DrawCircle(ballX,ballY , 20, WHITE);

        EndDrawing();
    }


    CloseWindow();
    return 0;
}