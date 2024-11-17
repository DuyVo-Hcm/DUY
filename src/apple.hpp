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
    void RandomPosNotinSnake(std::deque<Vector2> snakeBody);
    Vector2 getPosition();
};
