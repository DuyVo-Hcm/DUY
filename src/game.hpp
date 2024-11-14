#pragma once
#include "apple.hpp"
#include "score.hpp"
#include "frame.hpp"

class Game
{
private:
    Snake snake=Snake();
    Apple apple=Apple(snake.bodySnake);
    bool running=true;
    Score score=Score();
    Frame frame=Frame();
public:
    void Draw();
    void Update();
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
};