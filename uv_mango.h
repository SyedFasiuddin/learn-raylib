#ifndef UV_MANGO_H_
#define UV_MANGO_H_

#include <stdio.h>
#include <raylib.h>
#include <rlgl.h>

void uv_mango(void);

#endif // UV_MANGO_H_

#ifdef UV_MANGO_IMPL

#define WIDTH 500
#define HEIGHT 500

void uv_mango(void) {
    Color bg = { .r = 0x18, .g = 0x18, .b = 0x18, .a = 0xFF };

    InitWindow(WIDTH, HEIGHT, "UV Mango");
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
}

#endif // UV_MANGO_IMPL
