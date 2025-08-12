#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Collision Demo");
    SetTargetFPS(60);

    // Player setup
    Rectangle player = {100, 100, 50, 50};
    float playerSpeed = 4.0f;

    // Enemy setup
    Rectangle enemy = {400, 300, 50, 50};

    while (!WindowShouldClose()) {
        // --- Input ---
        if (IsKeyDown(KEY_RIGHT)) player.x += playerSpeed;
        if (IsKeyDown(KEY_LEFT)) player.x -= playerSpeed;
        if (IsKeyDown(KEY_DOWN)) player.y += playerSpeed;
        if (IsKeyDown(KEY_UP)) player.y -= playerSpeed;

        // --- Collision check ---
        bool isColliding = CheckCollisionRecs(player, enemy);

        // --- Drawing ---
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangleRec(player, BLUE);
        DrawRectangleRec(enemy, RED);

        if (isColliding) {
            DrawText("Collision!", 350, 20, 20, DARKPURPLE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
