#include <cmath>
#include <iostream>
#include "raylib.h"
#include "Player.h"
#include "AI.h"
#include "WhiteWall.h"
#include "Window.h"

int main()
{
    // window aka frame
    Window window;
    InitWindow(window.width, window.height, "My First Raylib Game");
    SetTargetFPS(60);

    // player -------
    Player player;

    // AI ---------
    AI ai;
    double angle;
    int rayendX;
    int rayendY;
    const double fan45 = (45 * 3.141) / 180;
    const double fan90 = 3.141 / 2;
    const int rayLength = ai.radius * 4;

    // obstacles --------
    WhiteWall whiteWall;

    // variables -------
    int distanceX;
    int distanceY;
    int posativeDistanceX;
    int posativeDistanceY;

    while (!WindowShouldClose())
    {
        // player ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
        if ((IsKeyDown(KEY_W)) && (IsKeyDown(KEY_D))) { // up + right
            player.up_right();
        }
        else if ((IsKeyDown(KEY_W)) && (IsKeyDown(KEY_A))) { // up + left
            player.up_left();
        }
        else if ((IsKeyDown(KEY_S)) && (IsKeyDown(KEY_D))) { // down + right
            player.down_right();
        }
        else if ((IsKeyDown(KEY_S)) && (IsKeyDown(KEY_A))) { // down + left
            player.down_left();
        }

        else if (IsKeyDown(KEY_W)) { // up
            player.up();
        }
        else if (IsKeyDown(KEY_S)) {// down
            player.down();
        }
        else if (IsKeyDown(KEY_A)) { // left
            player.left();
        }
        else if (IsKeyDown(KEY_D)) { // right
            player.right();
        }

        // AI -----------------------------------------------------------------------------------------------------------------------------------------------------------------

        // ray maths
        distanceX = player.ballX - ai.ballX;
        distanceY = player.ballY - ai.ballY;
        angle = std::atan2(distanceY, distanceX);

        // we are using the unit circle here everything is in radians so sin is Y and cos is the X
        // 5 ray casts offset
        // center
        ai.rayEndCenterX = ai.ballX + std::cos(angle) * rayLength;
        ai.rayEndCenterY = ai.ballY + std::sin(angle) * rayLength;
        // + 45 / - 45
        ai.rayEnd45X = ai.ballX + std::cos(angle + fan45) * rayLength;
        ai.rayEnd45Y = ai.ballY + std::sin(angle + fan45) * rayLength;
        ai.rayEndNeg45X = ai.ballX + std::cos(angle - fan45) * rayLength;
        ai.rayEndNeg45Y = ai.ballY + std::sin(angle - fan45) * rayLength;
        // + 90 / - 90
        ai.rayEnd90X = ai.ballX + std::cos(angle + fan90) * rayLength;
        ai.rayEnd90Y = ai.ballY + std::sin(angle + fan90) * rayLength;
        ai.rayEndNeg90X = ai.ballX - std::cos(angle + fan90) * rayLength;
        ai.rayEndNeg90Y = ai.ballY - std::sin(angle + fan90) * rayLength;
        ai.DrawRays(angle, fan90, fan45, rayLength);

        // debugging x and y distance lines
        DrawLine(player.ballX, ai.ballY, ai.ballX, ai.ballY, PINK);
        DrawLine(ai.ballX, player.ballY, ai.ballX, ai.ballY, PURPLE);

        // used for moving the ball swards the player
        posativeDistanceX = std::abs(player.ballX - ai.ballX);
        std::cout << posativeDistanceX << std::endl;
        posativeDistanceY = std::abs(player.ballY - ai.ballY);
        std::cout << posativeDistanceY << std::endl;

        // both are if and not if/else_if as we are chacking for both at the same time and not one after another
        ai.MoveToPlayer(posativeDistanceX, posativeDistanceY, player);

        // boarder collision ------------------------------------------------------------------------------------------------------------------------------------------------
        window.BoarderCollision(player);


        BeginDrawing();
        ClearBackground(BLACK);
        // player ------
        player.Draw();

        // AI -------
        ai.Draw();

        // obstacles -------
        DrawRectangle(whiteWall.wallX, whiteWall.wallY, whiteWall.wallWidth, whiteWall.wallHeight, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
