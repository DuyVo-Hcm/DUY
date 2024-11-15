#include "game.hpp"
#include "button.hpp"
using namespace std;

int main()
{
    InitWindow(cellSize *cellCount, cellSize * cellCount, "SnakeGame");
    SetTargetFPS(60); 

    Texture2D background=LoadTexture("ImageSnakegame/background.png");
    Button startButton{"ImageSnakegame/start_button.png", {450, 150}, 0.65};
    Button exitButton{"ImageSnakegame/exit_button.png", {450, 300}, 0.65};
    Game *game=new Game();

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
                    game->Update();

                if(IsKeyPressed(KEY_UP) && game->getSnake()->getDirection().y != 1)
                    game->getSnake()->setDirection({0, -1});

                if(IsKeyPressed(KEY_DOWN) && game->getSnake()->getDirection().y != -1)
                    game->getSnake()->setDirection({0, 1});

                if(IsKeyPressed(KEY_LEFT) && game->getSnake()->getDirection().x != 1)
                    game->getSnake()->setDirection({-1, 0});

                if(IsKeyPressed(KEY_RIGHT) && game->getSnake()->getDirection().x != -1)
                    game->getSnake()->setDirection({1, 0});
                
                ClearBackground(darkGreen);
                DrawRectangleLinesEx(Rectangle{ (float)offset - 5, (float)offset - 5, (float)cellSize *cellCount + 10, (float)cellSize *cellCount+10}, 5, darkGreen);
                game->Draw();
                EndDrawing();

                if(!game->isRunning())
                {
                    string score="Score: " + to_string(game->getScore().GetScore());

                    ifstream inputFile("src/maxscore.txt");
                    int record;
                    inputFile>>record;

                    bool breakrecord=false;
                    if(game->getScore().GetScore()>record)
                    {
                        breakrecord=true;
                        ofstream outputFile("src/maxscore.txt");
                        outputFile<<game->getScore().GetScore();
                        record=game->getScore().GetScore();
                    }

                    string max_score="Max Score: " + to_string(record);
                    
                    delete game;
                    game = new Game();

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