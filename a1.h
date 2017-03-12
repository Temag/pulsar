#include <time.h>

typedef struct walls{
    int start[2];
    int end[2];
    int direction;
    int current_length;

}wall;

enum directions{
    LEFT, RIGHT, UP, DOWN
}direction;

enum enemy_type{
  RED, YELLOW
}type;

typedef struct{
  enum enemy_type t;
  enum directions d;
  int state;
  int x;
  int y;
  int z;
}enemy;

void chooseWall();

void moveWall();

void drawEnemy(enemy e);

void eraseEnemy(enemy e);

void enemyMovement(enemy *e);

int lineOfSight();

void enemyShoot();

void animateEnemy(enemy *e);
