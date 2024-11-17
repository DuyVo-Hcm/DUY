#include "game.hpp"

void Game::Draw()
{
    snake->Draw();
    apple.Draw();
    score.DisplayScore(20, 20);
}

void Game::Update()
{
    if(running)
    {
        snake->Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }
}

void Game::CheckCollisionWithFood()
{
    if (Vector2Equals(snake->getbodySnake()[0], apple.getPosition()))
    {
        apple.RandomPosNotinSnake(snake->getbodySnake());
        snake->setAddSegment();
        score.UpdateScore(1);
    }
    
}

void Game::CheckCollisionWithEdges()
{
    if (snake->getbodySnake()[0].x==cellCount || snake->getbodySnake()[0].x==-1) running=false;
    if (snake->getbodySnake()[0].y==cellCount || snake->getbodySnake()[0].y==-1) running=false;
}

void Game::CheckCollisionWithTail()
{
    std::deque<Vector2> headlessBody=snake->getbodySnake();
    headlessBody.pop_front();
    if(ElementInDeque(snake->getbodySnake()[0], headlessBody)) running=false;
}

bool Game::isRunning() {return running;}

Score Game::getScore() {return score;}

Snake* Game::getSnake() 
{
    return snake;
}
