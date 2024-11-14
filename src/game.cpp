#include "game.hpp"

void Game::Draw()
{
    snake.Draw();
    apple.Draw();
    score.DisplayScore(20, 20);
    frame.DrawFrame(130, 60);
}

void Game::Update()
{
    if(running)
    {
        snake.Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }
}

void Game::CheckCollisionWithFood()
{
    if (Vector2Equals(snake.bodySnake[0], apple.position))
    {
        apple.position=apple.RandomPosNotinSnake(snake.bodySnake);
        snake.addSegment=true;
        score.UpdateScore(1);
    }
    
}

void Game::CheckCollisionWithEdges()
{
    if (snake.bodySnake[0].x==cellCount || snake.bodySnake[0].x==-1) running=false;
    if (snake.bodySnake[0].y==cellCount || snake.bodySnake[0].y==-1) running=false;
}

void Game::CheckCollisionWithTail()
{
    deque<Vector2> headlessBody=snake.bodySnake;
    headlessBody.pop_front();
    if(ElementInDeque(snake.bodySnake[0], headlessBody)) running=false;
}