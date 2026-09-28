#include "raylib.h"
#include <iostream>
#include <string>

std::string osname();

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    std::string os = std::string("Congrats! raylib is working on ") + osname();

    InitWindow(screenWidth, screenHeight, "raylib example - basic window");
    SetTargetFPS(60);
    
    Image checkedImage = GenImageChecked(screenWidth, screenHeight, 20, 20, LIGHTGRAY, GRAY);
    Texture2D backgroundTexture = LoadTextureFromImage(checkedImage);
    UnloadImage(checkedImage); 
    
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(backgroundTexture, 0, 0, WHITE);

            int recWidth = 640;
            int recHeight = 120;
            int posX = (screenWidth - recWidth) / 2;
            int posY = (screenHeight - recHeight) / 2;
            DrawRectangle(
                posX, 
                posY, 
                recWidth, 
                recHeight, 
                Color {80, 80, 80, 255} // DARKGRAY
            );

            int fontsize = 20;
            int textWidth = MeasureText(os.c_str(), fontsize);
            int textX = (screenWidth - textWidth) / 2;
            int textY = (screenHeight - fontsize) / 2;
            DrawText(os.c_str(), textX, textY, fontsize, LIGHTGRAY);

            EndDrawing();
    }

    CloseWindow();
    return 0;
}

std::string osname() {
#if defined(__APPLE__)
    return "macOS\n";
#elif defined(__linux__)
    return "Linux\n";
#elif defined(_WIN32)
    return "Windows\n";
#else
    return "Unknown OS\n";
#endif
}