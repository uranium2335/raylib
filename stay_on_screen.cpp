#include <raylib.h>

int main(){
    int Xballpos = 500;
    int Yballpos = 500;

    int ballspeed = 10;

    InitWindow(1000,1000 , "having fun");
    SetTargetFPS(120);

    //game loop
    while (WindowShouldClose)
    {
        // keeps ball on screen
        // X axis
        if(Xballpos == 10){
            ballspeed = 0;
            Xballpos += 20;
            ballspeed = 10;
        }if(Xballpos == 990){
            ballspeed = 0;
            Xballpos -= 20;
            ballspeed = 10;
        }      
        // Y axis
        if(Yballpos == 10){
            ballspeed = 0;
            Yballpos += 20;
            ballspeed = 10;
        }if(Yballpos == 990){
            ballspeed = 0;
            Yballpos -= 20;
            ballspeed = 10;
        }

        //arrow key movments
        if(IsKeyDown(KEY_UP)){
            Yballpos -= ballspeed;
        }if(IsKeyDown(KEY_DOWN)){
            Yballpos += ballspeed;
        }if(IsKeyDown(KEY_LEFT)){
            Xballpos -= ballspeed;
        }if(IsKeyDown(KEY_RIGHT)){
            Xballpos += ballspeed;
        }

        //screen drawing
        BeginDrawing();
        DrawCircle(Xballpos,Yballpos, 20 , WHITE);
        ClearBackground(BLACK);

        EndDrawing();
    }
    

    CloseWindow();
    return 0;
}