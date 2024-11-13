#include <iostream>

int main() {
    class Frame {
    public:
        void DrawFrame(int width, int height) {

            for (int i = 0; i < width; i++) {
                std::cout << "-";
            }
            std::cout << std::endl;

            for (int i = 0; i < height - 2; i++) {
                std::cout << "|";
                for (int j = 0; j < width - 2; j++) {
                    std::cout << " ";
                }
                std::cout << "|" << std::endl;
            }

            for (int i = 0; i < width; i++) {
                std::cout << "-";
            }
            std::cout << std::endl;
        }
    };


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


    Frame frame;
    Score score;

    frame.DrawFrame(40, 20);

    score.UpdateScore(10);
    score.DisplayScore(5, 5);

    return 0;
}