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
      case 0:
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
  switch(e->d)
  {
    case LEFT:
      if(world[e->x + 3][4][e->z] == 0 && world[e->x + 6][4][e->z] != 8 && world[e->x + 6][1][e->z] != 3)
      {
        eraseEnemy(*e);
        e->x++;
        drawEnemy(*e);
      }
      else
      {
        int r = rand()%3;
        switch(r)
        {
          case 0:
            e->d = RIGHT;
            break;
          case 1:
            e->d = DOWN;
            break;
          case 2:
            e->d = UP;
            break;
        }
      }
      break;
    case RIGHT:
      if(world[e->x - 3][4][e->z] == 0 && world[e->x-6][4][e->z] != 8 && world[e->x - 6][1][e->z] != 3)
      {
        eraseEnemy(*e);
        e->x--;
        drawEnemy(*e);
      }
      else
      {
        int r = rand()%3;
        switch(r)
        {
          case 0:
            e->d = LEFT;
            break;
          case 1:
            e->d = DOWN;
            break;
          case 2:
            e->d = UP;
            break;
        }
      }
      break;
    case UP:
      if(world[e->x][4][e->z + 3] == 0 && world[e->x][4][e->z + 6] != 8 && world[e->x][1][e->z + 6] != 3)
      {
        eraseEnemy(*e);
        e->z++;
        drawEnemy(*e);
      }
      else
      {
        int r = rand()%3;
        switch(r)
        {
          case 0:
            e->d = RIGHT;
            break;
          case 1:
            e->d = DOWN;
            break;
          case 2:
            e->d = LEFT;
            break;
        }
      }
      break;
    case DOWN:
      if(world[e->x][4][e->z - 3] == 0 && world[e->x][4][e->z - 6] != 8 && world[e->x][1][e->z - 6] != 3)
      {
        eraseEnemy(*e);
        e->z--;
        drawEnemy(*e);
      }
      else
      {
        int r = rand()%3;
        switch(r)
        {
          case 0:
            e->d = RIGHT;
            break;
          case 1:
            e->d = LEFT;
            break;
          case 2:
            e->d = UP;
            break;
        }
      }
      break;
  }
}

int lineOfSight(enemy *e, int xend, int zend)
{
  int xdif, zdif, j, slope;
  float xratio, zratio, x, z;
  double hyp;
  xdif = xend - e->x;
  zdif = zend - e->z;
  hyp = sqrt(pow(xdif, 2) + pow(zdif,2));
  zratio = zdif/hyp;
  xratio = xdif/hyp;
  x = e->x;
  z = e->z;
  j=0;
  while(j<(abs(xdif/(1*xratio))) || j<(abs(zdif/(1*zratio))))
  {
    x = x + (1*xratio);
    z = z + (1*zratio);
    if(world[(int)x][1][(int)z] == 2 || world[(int)x][1][(int)z] == 5)
    {
      return 0;
    }
    j++;
  }
  if(e->projectile_flag == 0)
  {
    e->xratio = xratio;
    e->zratio = zratio;
    e->px = e->x;
    e->pz = e->z;
  }
  return 1;
}

void animateEnemy(enemy *e)
{
  eraseEnemy(*e);
  e->state = (e->state + 1) % 4;
  drawEnemy(*e);
}

void projectileCollision(enemy *e)
{
  if(world[(int)e->px][1][(int)e->pz] == 2 || world[(int)e->px][1][(int)e->pz] == 5)
  {
    hideMob(e->projectile);
    e->projectile_flag = 0;
  }
}

void playerVector(float * xratio, float * zratio)
{
    float *fx = malloc(sizeof(float)), *fy = malloc(sizeof(float)), *fz = malloc(sizeof(float)), angle;

    getViewOrientation(fx, fy, fz);
    if(*fy < 0)
    {
      angle = ((int)*fy % 360) + 360;
      /*Implement vertical aiming*/
    }
    else
    {
      angle = (int)*fy % 360;
    }
    *xratio = sin(angle*M_PI/180);
    *zratio = -cos(angle*M_PI/180);
}

int dance(enemy e)
{
  float xratio, zratio, theta;

  playerVector(&xratio, &zratio);

  theta = acos((e.xratio * xratio) + (e.zratio * zratio));
  if(theta < M_PI/4 && theta > -M_PI/4)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
