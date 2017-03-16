#include <time.h>
#include <math.h>

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
  int projectile;
  int projectile_flag;
  float px;
  float pz;
  float xratio;
  float zratio;
}enemy;

void chooseWall();

void moveWall();

void drawEnemy(enemy e);

void eraseEnemy(enemy e);

void enemyMovement(enemy *e);

int lineOfSight(enemy *e, int xend, int zend);

void enemyShoot();

void animateEnemy(enemy *e);

void projectileCollision(enemy *e);

void playerVector(float *xratio, float *zratio);

int dance();
