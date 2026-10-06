#include "engine.hpp"

float hash::deltaTime() { return GetFrameTime(); }

bool hash::actionDown(Action a) {
    switch (a) {
        case Action::MoveLeft:  return IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT);
        case Action::MoveRight: return IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT);
        case Action::MoveUp:    return IsKeyDown(KEY_W) || IsKeyDown(KEY_UP);
        case Action::MoveDown:  return IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN);
    }
    return false;
}