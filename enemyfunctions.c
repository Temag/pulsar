#include "a1.h"
#include "Game_Engine/graphics.h"


void drawRedEnemy(renemy e)
{
  world[e.x+1][e.y+1][e.z+1] = 3;
  world[e.x+1][e.y+1][e.z-1] = 3;
  world[e.x+1][e.y-1][e.z+1] = 3;
  world[e.x+1][e.y-1][e.z-1] = 3;

  world[e.x+1][e.y+1][e.z] = 3;
  world[e.x+1][e.y+1][e.z] = 3;
  world[e.x+1][e.y-1][e.z] = 3;
  world[e.x+1][e.y-1][e.z] = 3;

  world[e.x-1][e.y+1][e.z+1] = 3;
  world[e.x-1][e.y+1][e.z-1] = 3;
  world[e.x-1][e.y-1][e.z+1] = 3;
  world[e.x-1][e.y-1][e.z-1] = 3;

  world[e.x-1][e.y+1][e.z] = 3;
  world[e.x-1][e.y+1][e.z] = 3;
  world[e.x-1][e.y-1][e.z] = 3;
  world[e.x-1][e.y-1][e.z] = 3;

  world[e.x][e.y][e.z] = 3;
  world[e.x][e.y][e.z+1] = 3;
  world[e.x][e.y][e.z-1] = 3;
}

void drawYellowEnemy(yenemy e)
{
  world[e.x+1][e.y][e.z] = 8;
  world[e.x+1][e.y+1][e.z] = 8;
  world[e.x+1][e.y-1][e.z] = 8;
  world[e.x+1][e.y][e.z+1] = 8;
  world[e.x+1][e.y][e.z-1] = 8;

  world[e.x-1][e.y][e.z] = 8;
  world[e.x-1][e.y+1][e.z] = 8;
  world[e.x-1][e.y-1][e.z] = 8;
  world[e.x-1][e.y][e.z+1] = 8;
  world[e.x-1][e.y][e.z-1] = 8;

  world[e.x][e.y+1][e.z+1] = 8;
  world[e.x][e.y-1][e.z+1] = 8;
  world[e.x][e.y+1][e.z-1] = 8;
  world[e.x][e.y-1][e.z-1] = 8;

  world[e.x+1][e.y+1][e.z+1] = 8;
  world[e.x+1][e.y+1][e.z-1] = 8;
  world[e.x+1][e.y-1][e.z+1] = 8;
  world[e.x+1][e.y-1][e.z-1] = 8;

  world[e.x-1][e.y+1][e.z+1] = 8;
  world[e.x-1][e.y+1][e.z-1] = 8;
  world[e.x-1][e.y-1][e.z+1] = 8;
  world[e.x-1][e.y-1][e.z-1] = 8;

  world[e.x][e.y+1][e.z] = 8;
  world[e.x][e.y-1][e.z] = 8;
  world[e.x][e.y][e.z+1] = 8;
  world[e.x][e.y][e.z-1] = 8;

}

void eraseRedEnemy(renemy e)
{
  world[e.x+1][e.y+1][e.z+1] = 0;
  world[e.x+1][e.y+1][e.z-1] = 0;
  world[e.x+1][e.y-1][e.z+1] = 0;
  world[e.x+1][e.y-1][e.z-1] = 0;

  world[e.x+1][e.y+1][e.z] = 0;
  world[e.x+1][e.y+1][e.z] = 0;
  world[e.x+1][e.y-1][e.z] = 0;
  world[e.x+1][e.y-1][e.z] = 0;

  world[e.x-1][e.y+1][e.z+1] = 0;
  world[e.x-1][e.y+1][e.z-1] = 0;
  world[e.x-1][e.y-1][e.z+1] = 0;
  world[e.x-1][e.y-1][e.z-1] = 0;

  world[e.x-1][e.y+1][e.z] = 0;
  world[e.x-1][e.y+1][e.z] = 0;
  world[e.x-1][e.y-1][e.z] = 0;
  world[e.x-1][e.y-1][e.z] = 0;

  world[e.x][e.y][e.z] = 0;
  world[e.x][e.y][e.z+1] = 0;
  world[e.x][e.y][e.z-1] = 0;
}

void eraseYellowEnemy(yenemy e)
{
  world[e.x+1][e.y][e.z] = 0;
  world[e.x+1][e.y+1][e.z] = 0;
  world[e.x+1][e.y-1][e.z] = 0;
  world[e.x+1][e.y][e.z+1] = 0;
  world[e.x+1][e.y][e.z-1] = 0;

  world[e.x-1][e.y][e.z] = 0;
  world[e.x-1][e.y+1][e.z] = 0;
  world[e.x-1][e.y-1][e.z] = 0;
  world[e.x-1][e.y][e.z+1] = 0;
  world[e.x-1][e.y][e.z-1] = 0;

  world[e.x][e.y+1][e.z+1] = 0;
  world[e.x][e.y-1][e.z+1] = 0;
  world[e.x][e.y+1][e.z-1] = 0;
  world[e.x][e.y-1][e.z-1] = 0;

  world[e.x+1][e.y+1][e.z+1] = 0;
  world[e.x+1][e.y+1][e.z-1] = 0;
  world[e.x+1][e.y-1][e.z+1] = 0;
  world[e.x+1][e.y-1][e.z-1] = 0;

  world[e.x-1][e.y+1][e.z+1] = 0;
  world[e.x-1][e.y+1][e.z-1] = 0;
  world[e.x-1][e.y-1][e.z+1] = 0;
  world[e.x-1][e.y-1][e.z-1] = 0;

  world[e.x][e.y+1][e.z] = 0;
  world[e.x][e.y-1][e.z] = 0;
  world[e.x][e.y][e.z+1] = 0;
  world[e.x][e.y][e.z-1] = 0;
}
