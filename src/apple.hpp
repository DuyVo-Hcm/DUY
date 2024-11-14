#pragma once
#include "snake.hpp"

class Apple
{
private:
    Vector2 position;
    Texture2D texture;
public:
    Apple(std::deque<Vector2> snakeBody);
    ~Apple();
    void Draw();
    Vector2 RandomPos();
    Vector2 RandomPosNotinSnake(std::deque<Vector2> snakeBody);
    Vector2 getPosition();
    void setPosition(Vector2 pos);
};