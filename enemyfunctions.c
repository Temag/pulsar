#include "a1.h"
#include "Game_Engine/graphics.h"

extern void createMob(int, float, float, float, float);
extern void setMobPosition(int, float, float, float, float);
extern void hideMob(int);
extern void showMob(int);

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

int lineOfSight(enemy e, int xend, int zend)
{
  int xdif, zdif, x, z;
  float delta_error, error;
  xdif = e.x - xend;
  zdif = e.z - zend;
  delta_error = abs(zdif/xdif);
  error = delta_error-0.5;
  z = e.z;
  if(xdif < 0 && zdif < 0)
  {
    for(x = e.x; x<xend; x++)
    {
      if(world[x][e.y][z] != 2 && world[x][e.y][z] != 6)
      {
        return 0;
      }
      error = error + delta_error;
      if(error > 0.5)
      {
        z = z - 1;
        error = error + 1.0;
      }
    }
  }
  else if(xdif < 0)
  {
    for(x = e.x; x<xend; x++)
    {
      if(world[x][e.y][z] != 2 && world[x][e.y][z] != 6)
      {
        return 0;
      }
      error = error + delta_error;
      if(error > 0.5)
      {
        z = z - 1;
        error = error - 1.0;
      }
    }
  }
  else if(zdif < 0)
  {
    for(x = e.x; x>xend; x--)
    {
      if(world[x][e.y][z] != 2 && world[x][e.y][z] != 6)
      {
        return 0;
      }
      error = error + delta_error;
      if(error > 0.5)
      {
        z = z + 1;
        error = error + 1.0;
      }
    }
  }
  else
  {
    for(x = e.x; x>xend; x--)
    {
      if(world[x][e.y][z] != 2 && world[x][e.y][z] != 6)
      {
        return 0;
      }
      error = error + delta_error;
      if(error > 0.5)
      {
        z = z - 1;
        error = error - 1.0;
      }
    }
  }
  return 1;
}

void enemyShoot(enemy *e, xend, zend)
{
  int xdif, zdif;
  float angle,xratio, zratio;
  xdif = xend - e->x;
  zdif = zend - e->z;

  if(xdif < 0 && zdif < 0)
  {
      angle = 3*M_PI/2 + atan(zdif/xdif);
      e->xratio = sin(angle);
      e->zratio = -cos(angle);
  }
  else if(xdif < 0)
  {
    angle = 3*M_PI/2 - atan(zdif/xdif);
    e->xratio = sin(angle);
    e->zratio = -cos(angle);
  }
  else if(zdif < 0)
  {
    angle = M_PI/2 - atan(zdif/xdif);
    e->xratio = sin(angle);
    e->zratio = -cos(angle);
  }
  else
  {
    angle = M_PI/2 + atan(zdif/xdif);
    e->xratio = sin(angle);
    e->zratio = -cos(angle);
  }
  createMob(e->projectile, e->x, 1.0, e->z, 180);
  e->px = e->x;
  e->pz = e->z;
  e->projectile_flag = 1;
}

void animateEnemy(enemy *e)
{
  eraseEnemy(*e);
  e->state = (e->state + 1) % 4;
  drawEnemy(*e);
}
