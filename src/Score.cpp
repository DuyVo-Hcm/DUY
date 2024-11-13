#include <iostream>

class Score {
private:
    int score;

public:
    Score() : score(0) {}

    void UpdateScore(int points) {
        score += points;
    }

    int GetScore() {
        return score;
    }

    void DisplayScore(int x, int y) {

        std::cout << "Score: " << score << std::endl;
    }
};