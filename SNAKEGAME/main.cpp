#include <raylib.h>
#include <iostream>
#include <deque>
#include "raymath.h"

using namespace std;

int cellSize = 30;
int cellCount = 25;

Color darkGreen = {20, 160, 133, 255}; 
Color Green = {20, 0, 0, 255};

double lastUpdateTime = 0;
bool ElementInDeque(Vector2 element, deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(deque[i], element))
        {
            return true;
        }
    }
    return false;
}

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

class Snake
{
    public:
        deque<Vector2> bodySnake = {Vector2{6, 9}, Vector2{5, 9},Vector2{4, 9}};
        Vector2 direction = {1, 0};

        void Draw()
        {
            for (unsigned int i = 0; i < bodySnake.size(); i++) {
                float x = bodySnake[i].x;
                float y = bodySnake[i].y;
                Rectangle segment = Rectangle{x * cellSize, y * cellSize, (float)cellSize, (float)cellSize};
                DrawRectangleRounded(segment, 0.5, 6, Green);
            }
        }
        void Update()
        {
            bodySnake.pop_back();
            bodySnake.push_front(Vector2Add(bodySnake[0], direction));
        }
};

class Apple
{

public:
    Vector2 position;
    Texture2D texture;

    Apple()
    {
        Image image = LoadImage("ImageSnakegame/Apple.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = RandomPos();
    }

    ~Apple()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 RandomPos()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{x, y};
    }
};
class Game
{
public:
    Snake snake = Snake();
    Apple apple = Apple();

    void Draw()
    {
        snake.Draw();
        apple.Draw();
    }
    void Update()
    {
        snake.Update();
    }

};

int main()
{


    InitWindow(cellSize *cellCount, cellSize * cellCount , "SNAKE GAME");
    SetTargetFPS(60);

    Apple apple = Apple();
    Snake snake = Snake();
    Game game = Game();
    while (!WindowShouldClose())
    {
       
        BeginDrawing();
          if (EventTriggered(0.2))
                game.Update();

            if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1)
              game.snake.direction = { 0, -1 };

            if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1)
                game.snake.direction = { 0, 1 };
        
            if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1)
                game.snake.direction = { -1, 0 };

            if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1)
                game.snake.direction = { 1, 0 };

        ClearBackground(darkGreen);
        game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}