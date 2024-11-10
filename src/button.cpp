#include "button.hpp"

Button::Button(const char *imagePath, Vector2 imagePosition)
{
    Texture=LoadTexture(imagePath);
}

Button::~Button()
{
    UnloadTexture(Texture);
}

void Button::Draw()
{
    DrawTexture(Texture, position.x, position.y, WHITE);
}
