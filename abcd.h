#ifndef ABCD_H_
#define ABCD_H_

#include <raylib.h>
#include <stdio.h>

void abcd(void);

#endif // ABCD_H_

#ifdef ABCD_IMPL_

#define WIDTH 500
#define HEIGHT 500

void abcd(void) {
    Color bg = { .r = 0x18, .g = 0x18, .b = 0x18, .a = 0xFF };

    SetWindowState(4); // resizable
    InitWindow(WIDTH, HEIGHT, "ABCD");
    InitAudioDevice();

    Texture2D texture;
    Sound sound;

    while (!WindowShouldClose()) {
        int ch = GetCharPressed();
        if (ch > 0 && ((ch >= 'a') && (ch <= 'z'))) {
            if (IsTextureReady(texture)) {
                UnloadTexture(texture);
            }
            Image img = LoadImage(TextFormat("assets/%c.png", ch));
            ImageResize(&img, WIDTH, HEIGHT);
            if (IsImageReady(img)) texture = LoadTextureFromImage(img);
            UnloadImage(img);

            if (IsSoundReady(sound)) {
                StopSound(sound);
                UnloadSound(sound);
            }
            sound = LoadSound(TextFormat("assets/%c.mp3", ch));
            PlaySound(sound);
        }

        BeginDrawing();
        {
            ClearBackground(bg);
            if (IsTextureReady(texture)) DrawTexture(texture, 0, 0, WHITE);
        }
        EndDrawing();
    }

    if (IsTextureReady(texture)) {
        UnloadTexture(texture);
    }

    if (IsSoundReady(sound)) {
        StopSound(sound);
        UnloadSound(sound);
    }

    CloseAudioDevice();
    CloseWindow();

    return;
}

#endif // ABCD_IMPL_
