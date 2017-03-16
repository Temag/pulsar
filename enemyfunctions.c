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
      if(world[e->x + 2][4][e->z] == 0 && world[e->x + 3][4][e->z] != 8 && world[e->x + 3][1][e->z] != 3)
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
      if(world[e->x - 2][4][e->z] == 0 && world[e->x-3][4][e->z] != 8 && world[e->x - 3][1][e->z] != 3)
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
      if(world[e->x][4][e->z + 2] == 0 && world[e->x][4][e->z + 3] != 8 && world[e->x][1][e->z + 3] != 3)
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
      if(world[e->x][4][e->z - 2] == 0 && world[e->x][4][e->z - 3] != 8 && world[e->x][1][e->z - 3] != 3)
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

int lineOfSight(enemy *e, int xend, int zend, int yend)
{
  int xdif, ydif, zdif, j, slope;
  float xratio, zratio, yratio, x, z, y;
  double hyp, hyp1;
  xdif = xend - e->x;
  zdif = zend - e->z;
  ydif = yend - e->y;
  hyp = sqrt(pow(xdif, 2) + pow(zdif,2));
  hyp1 = sqrt(pow(hyp, 2) + pow(ydif, 2));
  yratio = ydif/hyp1;
  zratio = zdif/hyp;
  xratio = xdif/hyp;
  x = e->x;
  z = e->z;
  y = e->y;
  j=0;
  while(j<(abs(xdif/(1*xratio))) || j<(abs(zdif/(1*zratio))))
  {
    x = x + (1*xratio);
    z = z + (1*zratio);
    y = y + (1*yratio);
    if(world[(int)x][(int)y][(int)z] == 2 || world[(int)x][(int)y][(int)z] == 5)
    {
      return 0;
    }
    j++;
  }
  if(e->projectile_flag == 0)
  {
    e->xratio = xratio;
    e->zratio = zratio;
    e->yratio = yratio;
    e->px = e->x;
    e->pz = e->z;
    e->py = e->y;
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

void playerVector(float * xratio, float * zratio, float * yratio)
{
    float *fx = malloc(sizeof(float)), *fy = malloc(sizeof(float)), *fz = malloc(sizeof(float)), angle, anglex, anglez;

    getViewOrientation(fx, fy, fz);

    if(*fy < 0)
      angle = ((int)*fy % 360) + 360;
    else
      angle = (int)*fy % 360;

    if(*fx < 0)
      anglex = ((int)*fx % 360) + 360;
    else
      anglex = (int)*fx % 360;

    if(*fz < 0)
      anglez = ((int)*fz % 360) + 360;
    else
      anglez = (int)*fz % 360;

    *yratio = -sin(anglex*M_PI/180) + -sin(anglez*M_PI/180);
    *xratio = sin(angle*M_PI/180);
    *zratio = -cos(angle*M_PI/180);
}

int dance(enemy e)
{
  float xratio, zratio, yratio, theta;

  playerVector(&xratio, &zratio, &yratio);

  theta = acos((e.xratio * xratio) + (e.yratio * yratio) + (e.zratio * zratio));
  if(theta < M_PI/4 && theta > -M_PI/4)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
