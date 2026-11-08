#ifndef RAYLIBTEST_WALL_H
#define RAYLIBTEST_WALL_H

#include "Player.h"

class Window {
public:
    int width = 800;
    int height = 600;

    void BoarderCollision(Player& player) const{
        if (player.ballX > width - player.radius) {
            player.ballX -= player.speed;
        }else if (player.ballX < 0 + player.radius) {
            player.ballX += player.speed;
        }
        else if (player.ballY > height - player.radius) {
            player.ballY -= player.speed;
        }else if (player.ballY < 0 + player.radius) {
            player.ballY += player.speed;
        }
    }
};
#endif //RAYLIBTEST_WALL_H
