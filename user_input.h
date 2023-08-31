#ifndef USER_INPUT_H_
#define USER_INPUT_H_

#include <raylib.h>

void user_input(void);

#endif // USER_INPUT_H_

#ifdef USER_INPUT_IMPL

/*
 * This will not handle backspace and text will not wrap on screen, it will
 * go beyond right edge, also the input buffer size is limited.
 */

#define WIDTH 500
#define HEIGHT 500
#define BUF_LEN 255

char buf[BUF_LEN + 1] = "\0";
int buf_idx = 0;

void user_input(void) {
    Color bg = { .r = 0x18, .g = 0x18, .b = 0x18, .a = 0xFF };

    InitWindow(WIDTH, HEIGHT, "User input handling");

    while (!WindowShouldClose()) {
        int key = GetCharPressed();
        while (key > 0) {
            // Printable characters only
            if ((key >= 32) && (key <= 125)) {
                buf[buf_idx] = (char) key;
                buf[buf_idx+1] = '\0';
                buf_idx++;
            }
            key = GetCharPressed();
        }

        BeginDrawing();
        {
            ClearBackground(bg);
            DrawText((void*)buf, 0, 0, 16, RAYWHITE);
        }
        EndDrawing();
    }
    CloseWindow();
}

#endif // USER_INPUT_IMPL
