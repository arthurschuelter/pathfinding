#pragma once

#include "./engine/engine.hpp"
#include <iostream>

class Character {
public: 
    Character();

    void Update(float dt);

    void DrawCharacter();
    void HandleMovement();
    void LogPosition();

    Vector2 position;
    float size;
    float speed;
    Color color;
};