#include <iostream>

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