#pragma once
#include "globalfunct.hpp"

class Snake
{
private:
    std::deque<Vector2> bodySnake = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};
    bool addSegment = false;

    Texture2D rightHeadTexture;
    Texture2D leftHeadTexture;
    Texture2D upHeadTexture;
    Texture2D downHeadTexture;
    Texture2D bodyHorizontalTexture;
    Texture2D bodyVerticalTexture;
    Texture2D rightTailTexture;
    Texture2D leftTailTexture;
    Texture2D upTailTexture;
    Texture2D downTailTexture;
    Texture2D topleftBodyTexture;
    Texture2D toprightBodyTexture;
    Texture2D bottomleftBodyTexture;
    Texture2D bottomrightBodyTexture;
public:
    Snake();
    ~Snake();
    void Draw();
    void Update();
    std::deque<Vector2> getbodySnake();
    void setAddSegment();
    Vector2 getDirection();
    void setDirection(Vector2 direct);
};