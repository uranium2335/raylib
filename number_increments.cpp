#include <raylib.h>

int main() {
    InitWindow(1000, 1000, "Number Update Every 1 Second");
    SetTargetFPS(60);


    int number = 0;
    float timer = 0.0f;

    while (!WindowShouldClose()) {
        // Update timer with frame time (seconds)
        timer += GetFrameTime();

        // If 1 second passed, increase number and reset timer
        if (timer >= 1.0f) {
            number++;
            timer = 0.0f;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // Draw the number in the center of the screen
        DrawText(TextFormat("%d", number), 500, 500, 40, DARKBLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
