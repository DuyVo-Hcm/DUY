#include <raylib.h>
#include <deque>
#include <fstream>
#include "raymath.h"
#include "button.hpp"
#include "score.hpp"
#include "frame.hpp"
using namespace std;

int cellSize=30;
int cellCount=25;

Color darkGreen={20, 160, 133, 255}; 
Color Black={20, 0, 0, 255};
Color Red={255, 0, 0, 200};

double lastUpdateTime=0;
bool ElementInDeque(Vector2 element, deque<Vector2> deque)
{
    for(unsigned int i=0; i<deque.size(); i++)
    {
        if(Vector2Equals(deque[i], element))
        {
            return true;
        }
    }
    return false;
}

bool EventTriggered(double interval)
{
    double currentTime=GetTime();
    if(currentTime-lastUpdateTime>=interval)
    {
        lastUpdateTime=currentTime;
        return true;
    }
    return false;
}

class Snake
{
    public:
        deque<Vector2> bodySnake={Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
        Vector2 direction={1, 0};
        bool addSegment=false;
        void Draw()
        {
            for(unsigned int i=0; i<bodySnake.size(); i++) 
            {
                float x=bodySnake[i].x;
                float y=bodySnake[i].y;
                Rectangle segment=Rectangle{x *cellSize, y *cellSize, (float)cellSize, (float)cellSize};
                if(i) DrawRectangleRounded(segment, 0.5, 6, Black);
                else DrawRectangleRounded(segment, 0.5, 6, Red);
            }
        }
        void Update()
        {   
            bodySnake.push_front(Vector2Add(bodySnake[0], direction));
            if(addSegment==true) addSegment=false;
            else bodySnake.pop_back();
        }
};

class Apple
{
public:
    Vector2 position;
    Texture2D texture;

    Apple(deque<Vector2> snakeBody)
    {
        Image image=LoadImage("ImageSnakegame/Apple.png");
        texture=LoadTextureFromImage(image);
        position=RandomPos(snakeBody);
    }

    void Draw()
    {
        DrawTexture(texture, position.x *cellSize, position.y *cellSize, WHITE);
    }

    Vector2 RandomPos(deque<Vector2> snakeBody)
    {
        float x=GetRandomValue(0, cellCount - 1);
        float y=GetRandomValue(0, cellCount - 1);
        return Vector2{x, y};
    }

    Vector2 RandomPosNotinSnakeAndFrame(deque<Vector2> snakeBody)
    {
        Vector2 position= RandomPos(snakeBody);
        while(ElementInDeque(position, snakeBody)) position=RandomPos(snakeBody);
        return position;
    }
};

class Game
{
public:
    Snake snake=Snake();
    Apple apple=Apple(snake.bodySnake);
    bool running=true;
    Score score=Score();
    Frame frame=Frame();

    void Draw()
    {
        snake.Draw();
        apple.Draw();
        score.DisplayScore(20, 20);
        frame.DrawFrame(130, 60);
    }

    void Update()
    {
        if(running)
        {
            snake.Update();
            CheckCollisionWithFood();
            CheckCollisionWithEdges();
            CheckCollisionWithTail();
        }
    }

    void CheckCollisionWithFood()
    {
        if (Vector2Equals(snake.bodySnake[0], apple.position))
        {
            apple.position=apple.RandomPosNotinSnakeAndFrame(snake.bodySnake);
            snake.addSegment=true;
            score.UpdateScore(1);
        }
        
    }

    void CheckCollisionWithEdges()
    {
        if (snake.bodySnake[0].x==cellCount || snake.bodySnake[0].x==-1) running=false;
        if (snake.bodySnake[0].y==cellCount || snake.bodySnake[0].y==-1) running=false;
    }

    void CheckCollisionWithTail()
    {
        deque<Vector2> headlessBody=snake.bodySnake;
        headlessBody.pop_front();
        if(ElementInDeque(snake.bodySnake[0], headlessBody)) running=false;
    }
};

int main()
{
    InitWindow(cellSize *cellCount, cellSize * cellCount, "SnakeGame");
    SetTargetFPS(60); 

    Texture2D background=LoadTexture("ImageSnakegame/background.png");
    Button startButton{"ImageSnakegame/start_button.png", {450, 150}, 0.65};
    Button exitButton{"ImageSnakegame/exit_button.png", {450, 300}, 0.65};
    Game game=Game();

    while(!WindowShouldClose())
    {
        Vector2 mousePosition=GetMousePosition();
        bool mousePressed=IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        bool exit=false;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);
        startButton.Draw();
        exitButton.Draw();
        EndDrawing();

        if(startButton.isPressed(mousePosition, mousePressed))
        {
            while(true)
            {
                if(exit) break;

                BeginDrawing();
                if(EventTriggered(0.2))
                    game.Update();

                if(IsKeyPressed(KEY_UP) && game.snake.direction.y != 1)
                    game.snake.direction = {0, -1};

                if(IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1)
                    game.snake.direction = {0, 1};

                if(IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1)
                    game.snake.direction = {-1, 0};

                if(IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1)
                    game.snake.direction = {1, 0};
                
                ClearBackground(darkGreen);
                game.Draw();
                EndDrawing();

                if(!game.running)
                {
                    string score="Score: " + to_string(game.score.GetScore());

                    ifstream inputFile("src/maxscore.txt");
                    int record;
                    inputFile>>record;

                    bool breakrecord=false;
                    if(game.score.GetScore()>record)
                    {
                        breakrecord=true;
                        ofstream outputFile("src/maxscore.txt");
                        outputFile<<game.score.GetScore();
                        record=game.score.GetScore();
                    }

                    string max_score="Max Score: " + to_string(record);

                    game=Game();

                    while(true)
                    {
                        BeginDrawing();
                        ClearBackground(darkGreen);
                        DrawText(score.c_str(), 60, 60, 50, BLACK);
                        DrawText(max_score.c_str(), 60, 130, 50, BLACK);
                        if(breakrecord) DrawText("Break Record!!!", 60, 300, 40, BLACK);
                        DrawText("Press Space to restart", 60, 400, 40, BLACK);
                        DrawText("Press Z to return to Menu", 60, 480, 40, BLACK);
                        EndDrawing();

                        if(IsKeyPressed(KEY_Z))
                        {
                            exit=true;
                            break;
                        }
                        if(IsKeyPressed(KEY_SPACE)) break;
                    }
                }
            }
        }
        if(exitButton.isPressed(mousePosition, mousePressed)) CloseWindow();
    }
}