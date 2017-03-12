#include "a1.h"
#include "Game_Engine/graphics.h"


void drawEnemy(enemy e)
{
  if(e.t == RED)
  {
    switch(e.state)
    {
      case 0:
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
        break;
      case 1:
        world[e.x][e.y][e.z] = 3;
        world[e.x][e.y][e.z+1] = 3;
        world[e.x][e.y][e.z-1] = 3;

        world[e.x][e.y+1][e.z] = 3;
        world[e.x][e.y+1][e.z+1] = 3;
        world[e.x][e.y+1][e.z-1] = 3;

        world[e.x][e.y-1][e.z] = 3;
        world[e.x][e.y-1][e.z-1] = 3;
        world[e.x][e.y-1][e.z+1] = 3;

        world[e.x+1][e.y][e.z] = 3;
        world[e.x+1][e.y][e.z+1] = 3;
        world[e.x+1][e.y][e.z-1] = 3;

        world[e.x-1][e.y][e.z] = 3;
        world[e.x-1][e.y][e.z+1] = 3;
        world[e.x-1][e.y][e.z-1] = 3;
        break;
        case 2:
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
          break;
      case 3:
        world[e.x][e.y][e.z] = 3;
        world[e.x][e.y][e.z+1] = 3;
        world[e.x][e.y][e.z-1] = 3;
        break;
    }
  }
  else if(e.t == YELLOW)
  {
    switch(e.state)
    {
      case 0:
        world[e.x][e.y][e.z] = 8;

        world[e.x+1][e.y+1][e.z+1] = 8;
        world[e.x+1][e.y+1][e.z-1] = 8;
        world[e.x+1][e.y-1][e.z+1] = 8;
        world[e.x+1][e.y-1][e.z-1] = 8;

        world[e.x-1][e.y+1][e.z+1] = 8;
        world[e.x-1][e.y+1][e.z-1] = 8;
        world[e.x-1][e.y-1][e.z+1] = 8;
        world[e.x-1][e.y-1][e.z-1] = 8;
        break;
      case 1:
        world[e.x][e.y][e.z] = 8;

        world[e.x+1][e.y][e.z+1] = 8;
        world[e.x+1][e.y][e.z-1] = 8;
        world[e.x-1][e.y][e.z+1] = 8;
        world[e.x-1][e.y][e.z-1] = 8;

        world[e.x][e.y+1][e.z+1] = 8;
        world[e.x][e.y-1][e.z+1] = 8;
        world[e.x][e.y+1][e.z-1] = 8;
        world[e.x][e.y-1][e.z-1] = 8;
        break;
      case 2:
        world[e.x][e.y][e.z] = 8;

        world[e.x+1][e.y+1][e.z+1] = 8;
        world[e.x+1][e.y+1][e.z-1] = 8;
        world[e.x+1][e.y-1][e.z+1] = 8;
        world[e.x+1][e.y-1][e.z-1] = 8;

        world[e.x-1][e.y+1][e.z+1] = 8;
        world[e.x-1][e.y+1][e.z-1] = 8;
        world[e.x-1][e.y-1][e.z+1] = 8;
        world[e.x-1][e.y-1][e.z-1] = 8;
        break;
      case 3:
        world[e.x][e.y][e.z] = 8;

        world[e.x+1][e.y][e.z+1] = 8;
        world[e.x+1][e.y][e.z-1] = 8;
        world[e.x-1][e.y][e.z+1] = 8;
        world[e.x-1][e.y][e.z-1] = 8;

        world[e.x][e.y+1][e.z+1] = 8;
        world[e.x][e.y-1][e.z+1] = 8;
        world[e.x][e.y+1][e.z-1] = 8;
        world[e.x][e.y-1][e.z-1] = 8;
        break;
    }
  }
}

void eraseEnemy(enemy e)
{
  if(e.t == RED)
  {
    switch(e.state)
    {
      case 1:
        world[e.x][e.y][e.z] = 0;
        world[e.x][e.y][e.z+1] = 0;
        world[e.x][e.y][e.z-1] = 0;

        world[e.x][e.y+1][e.z] = 0;
        world[e.x][e.y+1][e.z+1] = 0;
        world[e.x][e.y+1][e.z-1] = 0;

        world[e.x][e.y-1][e.z] = 0;
        world[e.x][e.y-1][e.z-1] = 0;
        world[e.x][e.y-1][e.z+1] = 0;

        world[e.x+1][e.y][e.z] = 0;
        world[e.x+1][e.y][e.z+1] = 0;
        world[e.x+1][e.y][e.z-1] = 0;

        world[e.x-1][e.y][e.z] = 0;
        world[e.x-1][e.y][e.z+1] = 0;
        world[e.x-1][e.y][e.z-1] = 0;
        break;
        case 2:
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
          break;
      case 3:
        world[e.x][e.y][e.z] = 0;
        world[e.x][e.y][e.z+1] = 0;
        world[e.x][e.y][e.z-1] = 0;
        break;
    }
  }
  else if(e.t == YELLOW)
  {
    switch(e.state)
    {
      case 0:
        world[e.x][e.y][e.z] = 0;

        world[e.x+1][e.y+1][e.z+1] = 0;
        world[e.x+1][e.y+1][e.z-1] = 0;
        world[e.x+1][e.y-1][e.z+1] = 0;
        world[e.x+1][e.y-1][e.z-1] = 0;

        world[e.x-1][e.y+1][e.z+1] = 0;
        world[e.x-1][e.y+1][e.z-1] = 0;
        world[e.x-1][e.y-1][e.z+1] = 0;
        world[e.x-1][e.y-1][e.z-1] = 0;
        break;
        case 1:
          world[e.x][e.y][e.z] = 0;

          world[e.x+1][e.y][e.z+1] = 0;
          world[e.x+1][e.y][e.z-1] = 0;
          world[e.x-1][e.y][e.z+1] = 0;
          world[e.x-1][e.y][e.z-1] = 0;

          world[e.x][e.y+1][e.z+1] = 0;
          world[e.x][e.y-1][e.z+1] = 0;
          world[e.x][e.y+1][e.z-1] = 0;
          world[e.x][e.y-1][e.z-1] = 0;
          break;
        case 2:
          world[e.x][e.y][e.z] = 0;

          world[e.x+1][e.y+1][e.z+1] = 0;
          world[e.x+1][e.y+1][e.z-1] = 0;
          world[e.x+1][e.y-1][e.z+1] = 0;
          world[e.x+1][e.y-1][e.z-1] = 0;

          world[e.x-1][e.y+1][e.z+1] = 0;
          world[e.x-1][e.y+1][e.z-1] = 0;
          world[e.x-1][e.y-1][e.z+1] = 0;
          world[e.x-1][e.y-1][e.z-1] = 0;
          break;
        case 3:
          world[e.x][e.y][e.z] = 0;

          world[e.x+1][e.y][e.z+1] = 0;
          world[e.x+1][e.y][e.z-1] = 0;
          world[e.x-1][e.y][e.z+1] = 0;
          world[e.x-1][e.y][e.z-1] = 0;

          world[e.x][e.y+1][e.z+1] = 0;
          world[e.x][e.y-1][e.z+1] = 0;
          world[e.x][e.y+1][e.z-1] = 0;
          world[e.x][e.y-1][e.z-1] = 0;
          break;
    }
  }
}

void enemyMovement(enemy *e)
{
  if(e->t == RED)
  {
    switch(e->d)
    {
      case LEFT:
        eraseEnemy(*e);
        e->x++;
        drawEnemy(*e);
        break;
      case RIGHT:
        eraseEnemy(*e);
        e->x--;
        drawEnemy(*e);
        break;
      case UP:
        eraseEnemy(*e);
        e->z++;
        drawEnemy(*e);
        break;
      case DOWN:
        eraseEnemy(*e);
        e->z--;
        drawEnemy(*e);
        break;
    }
  }

  else if(e->t == YELLOW)
  {
    switch(e->d)
    {
      case LEFT:
        eraseEnemy(*e);
        e->x++;
        drawEnemy(*e);
        break;
      case RIGHT:
        eraseEnemy(*e);
        e->x--;
        drawEnemy(*e);
        break;
      case UP:
        eraseEnemy(*e);
        e->z++;
        drawEnemy(*e);
        break;
      case DOWN:
        eraseEnemy(*e);
        e->z--;
        drawEnemy(*e);
        break;
    }
  }
}

int lineOfSight()
{

}

void enemyShoot()
{

}

void animateEnemy(enemy *e)
{
  eraseEnemy(*e);
  e->state = (e->state + 1) % 4;
  drawEnemy(*e);
}
