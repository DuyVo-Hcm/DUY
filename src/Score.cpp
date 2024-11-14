#include "score.hpp"

Score::Score()
    : score(0) {}

void Score::UpdateScore(int points) {this->score+=points;}

int Score::GetScore() {return this->score;}

void Score::DisplayScore(int x, int y)
{
    string text="Score: " + to_string(this->score);
    DrawText(text.c_str(), x, y, 50, BLACK);
}