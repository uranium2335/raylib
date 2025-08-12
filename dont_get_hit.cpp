#include <raylib.h>
#include <cstdlib>
#include <ctime>
#include <vector>

struct cube {
    int x;
    int y;
};

int main(){
    InitWindow(1000, 1000, "having fun");
    SetTargetFPS(120);
    srand(time(0));
    float timepassed = 0.0f;

    std::vector<cube> cubes;
    float spawntimer = 0.0f;
    const float spawninervals = 2.0f;
    const int cubesize = 30;
    const int fallspeed = 5;

    bool gameOver = false;

    while (!WindowShouldClose())
    {
        // Only update if game is not over
        if (!gameOver) {
            spawntimer += GetFrameTime();
            timepassed += GetFrameTime();

            if (spawntimer >= spawninervals && cubes.size() < 200) {
                int x = rand() % (1000 - cubesize);
                cubes.push_back({x, 0});
                spawntimer = 0.0f;
            }

            for (auto& cube : cubes) {
                cube.y += fallspeed;

                if (cube.y > 1000) {
                    cube.y = 0;
                    cube.x = rand() % (1000 - cubesize);
                }
            }

            // Collision detection
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();
            Rectangle playerRect = { (float)(mouseX - 10), (float)(mouseY - 10), 20, 20 };

            for (auto& cube : cubes) {
                Rectangle cubeRect = { (float)cube.x, (float)cube.y, (float)cubesize, (float)cubesize };
                if (CheckCollisionRecs(cubeRect, playerRect)) {
                    gameOver = true;
                    break;
                }
            }
        }

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw cubes
        for (auto& cube : cubes) {
            DrawRectangle(cube.x, cube.y, cubesize, cubesize, RED);
        }

        // Draw player (mouse) as circle
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        DrawCircle(mouseX, mouseY, 10, GREEN);

        // HUD
        DrawText(TextFormat("Cubes: %d", (int)cubes.size()), 10, 10, 20, WHITE);
        DrawText(TextFormat("time passed: %.2f", timepassed), 10, 30, 20, WHITE);

        if (gameOver) {
            DrawText("GAME OVER", 400, 500, 40, YELLOW);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
