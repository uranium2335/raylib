#include <raylib.h>
#include <cstdlib>
#include <ctime>
#include <vector>

int main(){
    InitWindow(800,700 , "pong vs ai");
    SetTargetFPS(120);
    srand(time(0));  // Seed random number generator

    //score
    int player_score = 0;
    int ai_score = 0;

    //player x ,y ,z(speed)
    Vector3 player_properties {10,300,5};

    //ai x ,y ,z(speed)
    Vector3 ai_properties {770,0,player_properties.z};

    //ball x ,y ,z(speed)
    Vector3 ball_properties {400,350,2};
    int direction = (rand() % 2) == 0 ? 1 : -1;

    while(WindowShouldClose() == false){
        // player logic
        if(IsKeyDown(KEY_UP)){
            player_properties.y -= player_properties.z;
        }else if(IsKeyDown(KEY_DOWN)){
            player_properties.y += player_properties.z;
        }  
        // ai logic
        if(ai_properties.y != player_properties.y){
            ai_properties.y = player_properties.y;
        }

        // ball logic
        // speed 12, direction either +1 or -1
        ball_properties.x += ball_properties.z * direction;

        // border collision
        if(player_properties.y <= 0) {
            player_properties.y += 10;
        }else if (player_properties.y >= 610){
            player_properties.y -=10;
        }

        // point system
        if(ball_properties.x <= 0){
            ball_properties.x = 400;
            direction = (rand() % 2) == 0 ? 1 : -1;
            ai_score += 1;
        }if(ball_properties.x >= 800){
            ball_properties.x = 400;
            direction = (rand() % 2) == 0 ? 1 : -1;
            player_score += 1;
        }

        BeginDrawing();
        // center line
        DrawRectangle(395,0 ,10,700 ,BLUE);
        // player
        DrawRectangle(player_properties.x,player_properties.y , 20,90 , WHITE);
        // ai
        DrawRectangle(ai_properties.x,ai_properties.y , 20,90 , WHITE);
        // ball
        DrawCircle(ball_properties.x ,ball_properties.y , 20 , WHITE);
        
        // point dysplay
        DrawText(TextFormat("%d",player_score) , 200,30 ,50 ,WHITE);
        DrawText(TextFormat("%d",ai_score) , 600,30 ,50 ,WHITE);

        // debug statments
        DrawText(TextFormat("ai y: %d",(int)ai_properties.y) , 10,680 ,15 ,WHITE);
        DrawText(TextFormat("player y: %d",(int)player_properties.y) , 100,680 ,15 ,WHITE);
        
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}