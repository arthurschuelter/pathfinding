#pragma once
#include "./engine/engine.hpp"

class Entity {
public:
    Entity() = default;

    void Update(float dt);

    Vector2 position;
    float width;
    float height;
    Vector2 size;

    Color color;
};