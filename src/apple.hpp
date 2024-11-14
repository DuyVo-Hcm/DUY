#pragma once
#include "snake.hpp"

class Apple
{
private:
    Vector2 position;
    Texture2D texture;
public:
    Apple(deque<Vector2> snakeBody);
    ~Apple();
    void Draw();
    Vector2 RandomPos();
    Vector2 RandomPosNotinSnake(deque<Vector2> snakeBody);
};