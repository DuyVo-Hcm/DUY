#include "apple.hpp"

Apple::Apple(std::deque<Vector2> snakeBody)
{
    texture=LoadTexture("ImageSnakegame/Apple.png");
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

void Apple::RandomPosNotinSnake(std::deque<Vector2> snakeBody)
{
    position=RandomPos();
    while(ElementInDeque(position, snakeBody)) position=RandomPos();
}

Vector2 Apple::getPosition() {return position;}
