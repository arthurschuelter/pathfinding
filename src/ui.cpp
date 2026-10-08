#include "ui.hpp"

Ui::Ui(int screenWidth, int screenHeight) 
    : screenWidth(screenWidth), screenHeight(screenHeight) {


    Image checkedImage = hash::GenImageChecked(screenWidth, screenHeight, 20, 20, LIGHTGRAY, GRAY);
    this->backgroundTexture = hash::LoadTextureFromImage(checkedImage);
    hash::UnloadImage(checkedImage); 
}

void Ui::Update(float dt) {
    this->DrawBackgound();
    this->DrawTestBox();
}

void Ui::DrawTestBox() {
    std::string os = std::string("Congrats! raylib is working on ") + osname();

    hash::DrawRectangle(
        this->posX, 
        this->posY, 
        this->recWidth, 
        this->recHeight, 
        Color {80, 80, 80, 255}
    );

    int fontsize = 20;
    int textWidth = hash::MeasureText(os.c_str(), fontsize);
    int textX = (this->screenWidth - textWidth) / 2;
    int textY = (this->screenHeight - fontsize) / 2;
    hash::DrawText(os.c_str(), textX, textY, fontsize, LIGHTGRAY);
}

void Ui::DrawBackgound() {
    hash::DrawTexture(backgroundTexture, 0, 0, WHITE);
}

std::string Ui::osname() {
#if defined(__APPLE__)
    return "macOS\n";
#elif defined(__linux__)
    return "Linux\n";
#elif defined(_WIN32)
    return "Windows\n";
#else
    return "Unknown OS\n";
#endif
}