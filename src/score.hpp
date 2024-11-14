#pragma once
#include <raylib.h>
#include <string>

class Score 
{
private:
    int score;
public:
    Score();
    void UpdateScore(int points);
    int GetScore();
    void DisplayScore(int x, int y);
};