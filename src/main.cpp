#include "./engine/engine.hpp"
#include "./character.hpp"
#include "./ui.hpp"

const int screenWidth = 800;
const int screenHeight = 450;

int main(void) {
    InitWindow(screenWidth, screenHeight, "raylib example - basic window");
    SetTargetFPS(60);

    Character* c = new Character();
    Ui* ui = new Ui(screenWidth, screenHeight);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            float dt = GetFrameTime();
            ui->Update(dt);
            c->Update(dt);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
