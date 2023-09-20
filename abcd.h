#ifndef ABCD_H_
#define ABCD_H_

#include <raylib.h>
#include <stdio.h>
#include "build/data.h"

void abcd(void);

#endif // ABCD_H_

#ifdef ABCD_IMPL_

#define WIDTH 500
#define HEIGHT 500

#define LIST_OF_CHARS X(97)  X(98)  X(99)  X(100) X(101) X(102) X(103) X(104)  \
                      X(105) X(106) X(107) X(108) X(109) X(110) X(111) X(112)  \
                      X(113) X(114) X(115) X(116) X(117) X(118) X(119) X(120)  \
                      X(121) X(122)

#define X(ch)                                                                  \
    if (in_ch == ch) {                                                         \
        if (IsTextureReady(texture)) {                                         \
            UnloadTexture(texture);                                            \
        }                                                                      \
        const char *image_filetype = ".png";                                   \
        Image img = LoadImageFromMemory(image_filetype, png_##ch, png_len_##ch);\
        ImageResize(&img, WIDTH, HEIGHT);                                      \
        if (IsImageReady(img)) texture = LoadTextureFromImage(img);            \
        UnloadImage(img);                                                      \
        if (IsSoundReady(sound)) {                                             \
            StopSound(sound);                                                  \
            UnloadSound(sound);                                                \
        }                                                                      \
        const char *wave_filtype = ".mp3";                                     \
        Wave wave = LoadWaveFromMemory(wave_filtype, mp3_##ch, mp3_len_##ch);  \
        sound = LoadSoundFromWave(wave);                                       \
        UnloadWave(wave);                                                      \
        PlaySound(sound);                                                      \
    }

void abcd(void) {
    Color bg = { .r = 0x18, .g = 0x18, .b = 0x18, .a = 0xFF };

    InitWindow(WIDTH, HEIGHT, "ABCD");
    SetWindowState(4); // resizable
    InitAudioDevice();

    Texture2D texture;
    Sound sound;

    while (!WindowShouldClose()) {
        int in_ch = GetCharPressed();
        if (in_ch > 0 && ((in_ch >= 'a') && (in_ch <= 'z'))) {
            LIST_OF_CHARS
            #undef X
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
