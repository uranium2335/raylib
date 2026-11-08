#ifndef RAYLIBTEST_PLAYER_H
#define RAYLIBTEST_PLAYER_H

class Player {
public:
    int ballX = 266;
    int ballY = 290;
    int radius = 20;
    int speed = 8;

    void Draw() {
        DrawCircle(ballX, ballY, radius, RED);
    }
    void left() {
        ballX -= speed;
    }
    void right() {
        ballX += speed;
    }
    void down() {
        ballY += speed;
    }
    void up() {
        ballY -= speed;
    }
    void up_left() {
        ballY += -speed;
        ballX -= speed;
    }
    void up_right() {
        ballY -= speed;
        ballX += speed;
    }
    void down_left() {
        ballY += speed;
        ballX -= speed;
    }
    void down_right() {
        ballY += speed;
        ballX += speed;
    }
};
#endif //RAYLIBTEST_PLAYER_H
