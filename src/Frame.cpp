#include "frame.hpp"

void frame::DrawFrame(int width, int height)
{
    DrawRectangleLines(0, 0, width, height, BLACK);
}