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

typedef struct{
  int x;
  int y;
  int z;
}renemy;

typedef struct{
  int x;
  int y;
  int z;
}yenemy;

void chooseWall();

void moveWall();

void drawRedEnemy(renemy e);

void drawYellowEnemy(yenemy e);

void eraseRedEnemy(renemy e);

void eraseYellowEnemy(yenemy e);
