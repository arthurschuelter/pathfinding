#pragma once

#include "raylib.h"

enum class Action { MoveLeft, MoveRight, MoveUp, MoveDown };

namespace hash {
    bool actionDown(Action a);

    float deltaTime();
}