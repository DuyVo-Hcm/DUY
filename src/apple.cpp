#include "apple.hpp"

Apple::Apple(std::deque<Vector2> snakeBody)
{
    Image image=LoadImage("ImageSnakegame/Apple.png");
    texture=LoadTextureFromImage(image);
    position=RandomPosNotinSnake(snakeBody);
}

Apple::~Apple()
{
    UnloadTexture(texture);
}

void Apple::Draw()
{
    DrawTexture(texture, offset + position.x*cellSize,offset + position.y*cellSize, WHITE);
}

Vector2 Apple::RandomPos()
{
    float x=GetRandomValue(0, cellCount-1);
    float y=GetRandomValue(0, cellCount-1);
    return Vector2{x, y};
}

Vector2 Apple::RandomPosNotinSnake(std::deque<Vector2> snakeBody)
{
    Vector2 position=RandomPos();
    while(ElementInDeque(position, snakeBody)) position=RandomPos();
    return position;
}

Vector2 Apple::getPosition() {return position;}

void Apple::setPosition(Vector2 pos) {position=pos;}