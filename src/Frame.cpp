#include "frame.hpp"

void Frame::DrawFrame(int width, int height)
{
    DrawRectangleLines(0, 0, width, height, BLACK);
}