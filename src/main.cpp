#include "./engine/engine.hpp"
#include "./character.hpp"
#include "./ui.hpp"

const int screenWidth = 800;
const int screenHeight = 450;

int main(void) {
    hash::InitWindow(screenWidth, screenHeight, "raylib example - basic window");
    hash::SetTargetFPS(60);

    Character* c = new Character();
    Ui* ui = new Ui(screenWidth, screenHeight);

    while (!hash::WindowShouldClose()) {
        hash::BeginDrawing();
            hash::ClearBackground(RAYWHITE);

            float dt = hash::GetFrameTime();
            ui->Update(dt);
            c->Update(dt);

        hash::EndDrawing();
    }

    hash::CloseWindow();
    return 0;
}
