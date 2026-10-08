#include "raylib.h"
#include "engine.hpp"

// Window
void hash::InitWindow(int width, int height, const char *title) { ::InitWindow(width, height, title); }
void hash::CloseWindow(void) { ::CloseWindow(); }
void hash::SetTargetFPS(int fps) { ::SetTargetFPS(fps); }
bool hash::WindowShouldClose(void) { return ::WindowShouldClose(); }
void hash::ClearBackground(Color color) { ::ClearBackground(color); }
void hash::BeginDrawing(void) { ::BeginDrawing(); }
void hash::EndDrawing(void) { return ::EndDrawing(); }

// Timing
float hash::GetFrameTime(void) { return ::GetFrameTime(); }
float hash::deltaTime() { return ::GetFrameTime(); }

bool hash::actionDown(Action a) {
    switch (a) {
        case Action::MoveLeft:  return IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT);
        case Action::MoveRight: return IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT);
        case Action::MoveUp:    return IsKeyDown(KEY_W) || IsKeyDown(KEY_UP);
        case Action::MoveDown:  return IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN);
    }
    return false;
}

void hash::DrawTexture(Texture2D texture, int posX, int posY, Color tint) {
    ::DrawTexture(texture, posX, posY, tint);
}

void hash::DrawRectangle(int posX, int posY, int width, int height, Color color) {
    ::DrawRectangle(posX, posY, width, height, color);
}

void hash::DrawText(const char *text, int posX, int posY, int fontSize, Color color) {
    ::DrawText(text, posX, posY, fontSize, color);
}

int hash::MeasureText(const char *text, int fontSize) {
    return ::MeasureText(text, fontSize);
}

Image hash::GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2) {
    return ::GenImageChecked(width, height, checksX, checksY, col1, col2);
}

Texture2D hash::LoadTextureFromImage(Image image) {
    return ::LoadTextureFromImage(image);
}

void hash::UnloadImage(Image image) {
    ::UnloadImage(image);
}
