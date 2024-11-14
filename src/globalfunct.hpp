#include <raylib.h>
#include <deque>
#include <fstream>
#include "raymath.h"
#include "globalvar.hpp"

bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);

bool EventTriggered(double interval);