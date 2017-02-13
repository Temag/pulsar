#include <time.h>

typedef struct walls{
    int start[2];
    int end[2];
    int direction;
    int current_length;

}wall;

enum wall_direction{
    LEFT, RIGHT, UP, DOWN
}direction;

void chooseWall();

void moveWall();
