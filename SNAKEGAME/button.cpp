#include "button.hpp"

Button::Button(const char *imagePath, Vector2 imagePosition)
{
    Texture = LoadTexture(imagePath);
}

Button::~Button()
{
    UnloadTexture(texture);
}

void Button::Draw()
{
    DrawTexture(texture, position, WHITE);
}
