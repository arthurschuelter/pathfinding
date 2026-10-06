#include "character.hpp"

Character::Character() {
    std::cout << "Character instantiated\n";

    this->position = Vector2 {0, 0};
    this->speed = 2.0f;
    this->color = RED;
    this->size = 32;
}

void Character::Update(float dt) {
    this->HandleMovement();
    this->DrawCharacter();
    // this->LogPosition();
}

void Character::HandleMovement() {
    if (IsKeyDown(KEY_RIGHT))   this->position.x += this->speed;
    if (IsKeyDown(KEY_LEFT))    this->position.x -= this->speed;
    if (IsKeyDown(KEY_UP))      this->position.y -= this->speed;
    if (IsKeyDown(KEY_DOWN))    this->position.y += this->speed;
}

void Character::LogPosition() {
    std::cout << "(x: " << this->position.x << ", y: " << this->position.y << ")\n";
}

void Character::DrawCharacter() {
    DrawRectangle(
        this->position.x, 
        this->position.y, 
        this->size, 
        this->size, 
        this->color
    );
}