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
    if (hash::actionDown(Action::MoveRight))    this->position.x += this->speed;
    if (hash::actionDown(Action::MoveLeft))     this->position.x -= this->speed;
    if (hash::actionDown(Action::MoveDown))     this->position.y += this->speed;
    if (hash::actionDown(Action::MoveUp))       this->position.y -= this->speed;
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