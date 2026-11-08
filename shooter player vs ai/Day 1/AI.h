#ifndef RAYLIBTEST_AI_H
#define RAYLIBTEST_AI_H

#include "Player.h"
// the AI will aim for 2 radiuses ahead of the player and go there

class AI {
public:
    int ballX = 533;
    int ballY = 300;
    int radius = 20;
    int speed = 4;
    // center
    int rayEndCenterX;
    int rayEndCenterY;
    // + 90
    int rayEnd90X;
    int rayEnd90Y;
    // + 45
    int rayEnd45X;
    int rayEnd45Y;
    // - 90
    int rayEndNeg90X;
    int rayEndNeg90Y;
    // - 45
    int rayEndNeg45X;
    int rayEndNeg45Y;


    void Draw() {
        DrawCircle(ballX, ballY, radius, BLUE);
    }
    void MoveToPlayer(int posativeDistanceX, int posativeDistanceY, Player& player) {
        // both are if and not if/else_if as we are chacking for both at the same time and not one after another
        if (posativeDistanceX > 5) {
            if (ballX > player.ballX) {
                ballX -= speed;
            }else {
                ballX += speed;
            }
        }
        if (posativeDistanceY > 5) {
            if (ballY > player.ballY) {
                ballY -= speed;
            }else {
                ballY += speed;
            }
        }
    }
    void DrawRays(double angle, double fan90, double fan45, int rayLength) {
        DrawLine(ballX, ballY, rayEndCenterX, rayEndCenterY, GREEN); // center
        DrawLine(ballX, ballY, ballX + std::cos(angle + fan90) * rayLength, ballY + std::sin(angle + fan90) * rayLength, GREEN); // +90 from center
        DrawLine(ballX, ballY, ballX - std::cos(angle + fan90) * rayLength, ballY - std::sin(angle + fan90) * rayLength, GREEN); // -90 from center
        DrawLine(ballX, ballY, ballX + std::cos(angle + fan45) * rayLength, ballY + std::sin(angle + fan45) * rayLength, DARKGREEN); // +45 from center
        DrawLine(ballX, ballY, ballX + std::cos(angle - fan45) * rayLength, ballY + std::sin(angle - fan45) * rayLength, DARKGREEN); // -45 from center
    }

};


#endif //RAYLIBTEST_AI_H
