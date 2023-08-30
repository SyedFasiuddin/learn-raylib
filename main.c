#include <stdio.h>
#include <raylib.h>
#include <rlgl.h>

#define WIDTH 500
#define HEIGHT 500

int main(void) {
    Color bg = { .r = 0x18, .g = 0x18, .b = 0x18, .a = 0xFF };

    InitWindow(WIDTH, HEIGHT, "Hello World raylib");
    Shader shader = LoadShader(NULL, "uv_mango.fs");
    Texture2D texture = { rlGetTextureIdDefault(), 1, 1, 1, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 };
    // Instead of flipping the y-axis, adjust the center and rotate the rectangle
    Vector2 rect_position = {
        .x = WIDTH/2 - WIDTH/4,
        .y = HEIGHT/2 + HEIGHT/4,
    };

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(bg);
            BeginShaderMode(shader);
            {
                DrawTextureEx(texture, rect_position, 270, WIDTH/2, bg);
            }
            EndShaderMode();
        }
        EndDrawing();
    }
    UnloadShader(shader);
    CloseWindow();

    return 0;
}
