#include "score.hpp"

Score::Score()
    : score(0) {}

void Score::UpdateScore(int points) {this->score+=points;}

int Score::GetScore() {return this->score;}

void Score::DisplayScore(int x, int y)
{
    std::string text="Score: " + std::to_string(this->score);
    DrawText(text.c_str(), x, y, 20, BLACK);
}