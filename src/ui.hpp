#pragma once

#include "./engine/engine.hpp"

#include <iostream>
#include <string>

class Ui {
public: 
    Ui(int screenWidth, int screenHeight);

    void Update(float dt);

    Vector2 position;
    float size;
    float speed;
    Color color;
    
    int screenWidth;
    int screenHeight;

private:
    void DrawTestBox();
    void DrawBackgound();

    std::string osname();

    int recWidth = 640;
    int recHeight = 120;

    int posX = (this->screenWidth - this->recWidth) / 2;
    int posY = (this->screenHeight - this->recHeight) / 2;

    // Checkered Background
    Texture2D backgroundTexture;
};