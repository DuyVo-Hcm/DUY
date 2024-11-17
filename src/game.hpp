#pragma once
#include "apple.hpp"
#include "score.hpp"

class Game
{
private:
    Snake *snake= new Snake();
    Apple apple=Apple(snake->getbodySnake());
    bool running=true;
    Score score=Score();
public:
    void Draw();
    void Update();
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    bool isRunning();
    Score getScore();
    Snake* getSnake();
};
