#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "a1.h"

#include "Game_Engine/graphics.h"
extern void setViewPosition(float, float, float);
extern void setViewOrientation(float, float, float);

extern enemy e[4];

extern keyCube key;

int total_walls = 0;

int wall_toggle = 0;

int old_wall_index;

int old_offset;

int new_offset;

clock_t before;

wall new_wall;

wall wall_array[30];

greenCube gcubes[2];

blueCube bcubes[2];

redCube rcubes[2];

blueCube fallingCubes[10];

void redCubeEffect()
{
  int i;
  for(i=0; i<4; i++)
  {
    eraseEnemy(e[i]);
    e[i].x = rand()%36;
    e[i].z = rand()%36;
  }
}

void blueCubeEffect()
{
  int i;
  for(i=0; i<10; i++)
  {
    fallingCubes[i].x = 2 + (rand()%5*6);
    fallingCubes[i].y = 6;
    fallingCubes[i].z = 2 + (rand()%5*6);
    world[fallingCubes[i].x][fallingCubes[i].y][fallingCubes[i].z] = 6;
  }
}

void greenCubeEffect()
{
  int x, z, nx, ny, nz;
  float *fx = malloc(sizeof(float)), *fy = malloc(sizeof(float)), *fz = malloc(sizeof(float));
  getViewPosition(fx, fy, fz);
  nx = (int)(-*fx);
  ny = (int)(-*fy);
  nz = (int)(-*fz);
  x = rand()%36;
  z = rand()%36;
  if(x%6 == 0)
  {
    x++;
  }
  if(z%6 == 0)
  {
    z++;
  }
  while(ny < 8)
  {
    ny++;
    setViewPosition((float)-nx, (float)-ny, (float)-nz);
  }
  if(x-(nx) < 0)
  {
    while(nx > x)
    {
      nx--;
      setViewPosition((float)-nx, (float)-ny, (float)-nz);
    }
  }
  else
  {
    while(nx < x)
    {
      nx++;
      setViewPosition((float)-nx, (float)-ny, (float)-nz);
    }
  }

  if(z-(nz) < 0)
  {
    while(nz > z)
    {
      nz--;
      setViewPosition((float)-nx, (float)-ny, (float)-nz);
    }
  }
  else
  {
    while(nz < z)
    {
      nz++;
      setViewPosition((float)-nx, (float)-ny, (float)-nz);
    }
  }
}

void initializeGame()
{
  int i, j, k, l=0, r;
  total_walls = 0;
  old_offset = 5;
  new_offset = 1;
  wall_toggle = 0;

  for(i=0; i<WORLDX; i++)
     for(j=0; j<WORLDY; j++)
        for(k=0; k<WORLDZ; k++)
           world[i][j][k] = 0;

  for(i=0; i<37; i++)
  {
    for(j=0; j<37; j++)
    {
        world[i][0][j] = 1;
    }
  }
  for(i=0; i<37; i++)
  {
    for(k=0; k<5; k++)
    {
      world[i][0+k][0] = 2;
      world[i][0+k][36] = 2;
    }
  }

  for(i=0; i<36; i++)
  {
    for(k=0; k<5; k++)
    {
      world[0][0+k][i] = 2;
      world[36][0+k][i] = 2;
    }
  }

  /*createPlayer(0, 52.0, 27.0, 52.0, 0.0);
  setPlayerPosition(0, 1.0, 1, 4.0, 0.0);*/
  setViewPosition(-2.0, -1.0, -2.0);
  setViewOrientation(0.0, 180.0, .0);

  /*
  Generate pillars every 6 spaces
  */
  for(i=6; i<36; i+=6)
  {
    for(j=6; j<36; j+=6)
    {
      for(k=1; k<5; k++)
      {
        world[j][k][i] = 7;
      }
    }
  }
   for(i=6; i<42; i+=6)
   {
       for(j=6; j<36; j+=6)
       {
           /*
            Generates walls running in the Z direction (parallel with starting orientation)
            */
           r = rand() % 2;
           if(r == 1 && total_walls < 30)
           {
               for(k=5; k>0; k--)
               {
                   for(l=1; l<5; l++)
                   {
                       world[j][l][i-k] = 2;
                   }
               }
               wall_array[total_walls].start[0] = j;
               wall_array[total_walls].start[1] = i;
               wall_array[total_walls].end[0] = j;
               wall_array[total_walls].end[1] = i-5;
               wall_array[total_walls].direction = DOWN;
               wall_array[total_walls].current_length = 5;
               total_walls++;
           }

           /*
            Generates walls running in the X direction (perpendicular to starting orientation)
            */
           r = rand() % 2;
           if(r == 1 && total_walls < 30)
           {
               for(k=5; k>0; k--)
               {
                   for(l=1; l<5; l++)
                   {
                       world[i-k][l][j] = 2;
                   }
               }
               wall_array[total_walls].start[0] = i;
               wall_array[total_walls].start[1] = j;
               wall_array[total_walls].end[0] = i-5;
               wall_array[total_walls].end[1] = j;
               wall_array[total_walls].direction = RIGHT;
               wall_array[total_walls].current_length = 5;
               total_walls++;
          }
      }
    }

  /*Create exit door*/
  for(i=0; i < 3; i++)
  {
    for(j=0; j < 3; j++)
    {
      world[1+j][1+i][36] = 5;
    }
  }

  /* Generate effect cubes */
  /* Key */
  key.x = 3 + (rand() % 5 + 1)*6;
  key.z = 3 + (rand() % 5 + 1)*6;
  key.y = 1;
  keyPlacement(key);

  for(i=0; i<2; i ++)
  {
    bcubes[i].x = 2 + (rand()%5*6);
    bcubes[i].y = 1;
    bcubes[i].z = 2 + (rand()%5*6);
    world[bcubes[i].x][1][bcubes[i].z] = 2;

    rcubes[i].x = 1 + (rand()%5*6);
    rcubes[i].y = 1;
    rcubes[i].z = 1 + (rand()%5*6);
    world[rcubes[i].x][1][rcubes[i].z] = 3;

    gcubes[i].x = 4 + (rand()%5*6);
    gcubes[i].y = 1;
    gcubes[i].z = 4 + (rand()%5*6);
    world[gcubes[i].x][1][gcubes[i].z] = 1;
  }

  /*Create Enemies*/
  e[0].t = RED;
  e[0].d = LEFT;
  e[0].projectile = 1;
  e[0].projectile_flag = 0;
  e[0].state = 0;
  e[0].x = 9;
  e[0].y = 2;
  e[0].z = 15;
  e[0].px = e[0].x;
  e[0].px = e[0].y;
  e[0].px = e[0].z;
  drawEnemy(e[0]);

  e[1].t = RED;
  e[1].d = RIGHT;
  e[1].projectile = 2;
  e[1].projectile_flag = 0;
  e[1].state = 0;
  e[1].x = 27;
  e[1].y = 2;
  e[1].z = 27;
  e[1].px = e[1].x;
  e[1].px = e[1].y;
  e[1].px = e[1].z;
  drawEnemy(e[1]);

  e[2].t = YELLOW;
  e[2].d = UP;
  e[2].projectile = 3;
  e[2].projectile_flag = 0;
  e[2].state = 0;
  e[2].x = 21;
  e[2].y = 2;
  e[2].z = 9;
  e[2].px = e[2].x;
  e[2].px = e[2].y;
  e[2].px = e[2].z;
  drawEnemy(e[2]);

  e[3].t = YELLOW;
  e[3].d = DOWN;
  e[3].projectile = 4;
  e[3].projectile_flag = 0;
  e[3].state = 0;
  e[3].x = 3;
  e[3].y = 2;
  e[3].z = 27;
  e[3].px = e[3].x;
  e[3].px = e[3].y;
  e[3].px = e[3].z;
  drawEnemy(e[3]);
}

void chooseWall()
{
    int r;
    r = rand() % total_walls;
    old_wall_index = r;

    /*
     Two special cases where the walls starting indeces are the outside wall rather than a pillar
     Changes the starting indeces to that of the closest pillar and generates the new wall using those
     parameteres
     Assigns new direction for the new wall or exits the function walls already exist on all other sides
     */
    if(wall_array[old_wall_index].start[0] == 36)
    {
        new_wall.start[0] = 30;
        new_wall.start[1] = wall_array[old_wall_index].start[1];
        new_wall.current_length = 0;

        if(world[new_wall.start[0]-1][1][new_wall.start[1]] == 0)
        {
          new_wall.direction = RIGHT;
        }
        else if(world[new_wall.start[0]][1][new_wall.start[1]+1] == 0)
        {
          new_wall.direction = UP;
        }
        else if(world[new_wall.start[0]][1][new_wall.start[1]-1] == 0)
        {
          new_wall.direction = DOWN;
        }
        else
        {
          wall_toggle = 1;
        }
    }
    else if(wall_array[old_wall_index].start[1] == 36)
    {
        new_wall.start[0] = wall_array[old_wall_index].start[0];
        new_wall.start[1] = 30;
        new_wall.current_length = 0;

        if(world[new_wall.start[0]+1][1][new_wall.start[1]] == 0)
        {
          new_wall.direction = LEFT;
        }
        else if(world[new_wall.start[0]-1][1][new_wall.start[1]] == 0)
        {
          new_wall.direction = RIGHT;
        }
        else if(world[new_wall.start[0]][1][new_wall.start[1]-1] == 0)
        {
          new_wall.direction = DOWN;
        }
        else
        {
          wall_toggle = 0;
          return;
        }
    }
    else
    {
        new_wall.start[0] = wall_array[old_wall_index].start[0];
        new_wall.start[1] = wall_array[old_wall_index].start[1];
        new_wall.current_length = 0;

        /*
         Assigns a new direction for the new wall to be used by the move function, or exits the function because
         walls already exist in all other directions
         */
        if(wall_array[old_wall_index].direction == UP)
        {
            if(world[new_wall.start[0]+1][1][new_wall.start[1]] == 0)
            {
              new_wall.direction = LEFT;
            }
            else if(world[new_wall.start[0]-1][1][new_wall.start[1]] == 0)
            {
              new_wall.direction = RIGHT;
            }
            else if(world[new_wall.start[0]][1][new_wall.start[1]-1] == 0)
            {
              new_wall.direction = DOWN;
            }
            else
            {
              wall_toggle = 0;
              return;
            }
        }
        else if(wall_array[old_wall_index].direction == DOWN)
        {
            if(world[new_wall.start[0]+1][1][new_wall.start[1]] == 0)
            {
              new_wall.direction = LEFT;
            }
            else if(world[new_wall.start[0]-1][1][new_wall.start[1]] == 0)
            {
              new_wall.direction = RIGHT;
            }
            else if(world[new_wall.start[0]][1][new_wall.start[1]+1] == 0)
            {
              new_wall.direction = UP;
            }
            else
            {
              wall_toggle = 0;
              return;
            }
        }
        else if(wall_array[old_wall_index].direction == LEFT)
        {
            if(world[new_wall.start[0]][1][new_wall.start[1]+1] == 0)
            {
              new_wall.direction = UP;
            }
            else if(world[new_wall.start[0]-1][1][new_wall.start[1]] == 0)
            {
              new_wall.direction = RIGHT;
            }
            else if(world[new_wall.start[0]][1][new_wall.start[1]-1] == 0)
            {
              new_wall.direction = DOWN;
            }
            else
            {
              wall_toggle = 0;
              return;
            }
        }
        else
        {
            if(world[new_wall.start[0]+1][1][new_wall.start[1]] == 0)
            {
              new_wall.direction = LEFT;
            }
            else if(world[new_wall.start[0]][1][new_wall.start[1]+1] == 0)
            {
              new_wall.direction = UP;
            }
            else if(world[new_wall.start[0]][1][new_wall.start[1]-1] == 0)
            {
              new_wall.direction = DOWN;
            }
            else
            {
              wall_toggle = 0;
              return;
            }
        }
    }
}

/*

*/
void moveWall()
{
    int i, j, k;
    if(wall_array[old_wall_index].start[0] == 36)
    {
        world[30+old_offset][1][wall_array[old_wall_index].start[1]] = 0;
        world[30+old_offset][2][wall_array[old_wall_index].start[1]] = 0;
        world[30+old_offset][3][wall_array[old_wall_index].start[1]] = 0;
        world[30+old_offset][4][wall_array[old_wall_index].start[1]] = 0;
        switch(new_wall.direction)
        {
          case 1:
              world[new_wall.start[0]-new_offset][1][new_wall.start[1]] = 2;
              world[new_wall.start[0]-new_offset][2][new_wall.start[1]] = 2;
              world[new_wall.start[0]-new_offset][3][new_wall.start[1]] = 2;
              world[new_wall.start[0]-new_offset][4][new_wall.start[1]] = 2;
              break;
          case 2:
              world[new_wall.start[0]][1][new_wall.start[1]+new_offset] = 2;
              world[new_wall.start[0]][2][new_wall.start[1]+new_offset] = 2;
              world[new_wall.start[0]][3][new_wall.start[1]+new_offset] = 2;
              world[new_wall.start[0]][4][new_wall.start[1]+new_offset] = 2;
              break;
          case 3:
              world[new_wall.start[0]][1][new_wall.start[1]-new_offset] = 2;
              world[new_wall.start[0]][2][new_wall.start[1]-new_offset] = 2;
              world[new_wall.start[0]][3][new_wall.start[1]-new_offset] = 2;
              world[new_wall.start[0]][4][new_wall.start[1]-new_offset] = 2;
              break;
        }

        old_offset--;
        new_offset++;
    }
    else if(wall_array[old_wall_index].start[1] == 36)
    {
        world[wall_array[old_wall_index].start[0]][1][30+old_offset] = 0;
        world[wall_array[old_wall_index].start[0]][2][30+old_offset] = 0;
        world[wall_array[old_wall_index].start[0]][3][30+old_offset] = 0;
        world[wall_array[old_wall_index].start[0]][4][30+old_offset] = 0;

        switch(new_wall.direction)
        {
          case 0:
              world[new_wall.start[0]+new_offset][1][new_wall.start[1]] = 2;
              world[new_wall.start[0]+new_offset][2][new_wall.start[1]] = 2;
              world[new_wall.start[0]+new_offset][3][new_wall.start[1]] = 2;
              world[new_wall.start[0]+new_offset][4][new_wall.start[1]] = 2;
              break;
          case 1:
              world[new_wall.start[0]-new_offset][1][new_wall.start[1]] = 2;
              world[new_wall.start[0]-new_offset][2][new_wall.start[1]] = 2;
              world[new_wall.start[0]-new_offset][3][new_wall.start[1]] = 2;
              world[new_wall.start[0]-new_offset][4][new_wall.start[1]] = 2;
              break;
          case 2:
              world[new_wall.start[0]][1][new_wall.start[1]+new_offset] = 2;
              world[new_wall.start[0]][2][new_wall.start[1]+new_offset] = 2;
              world[new_wall.start[0]][3][new_wall.start[1]+new_offset] = 2;
              world[new_wall.start[0]][4][new_wall.start[1]+new_offset] = 2;
              break;
        }

        old_offset--;
        new_offset++;
    }
    else
    {
        switch(wall_array[old_wall_index].direction)
        {
            case 0:
                world[wall_array[old_wall_index].start[0]+old_offset][1][wall_array[old_wall_index].start[1]] = 0;
                world[wall_array[old_wall_index].start[0]+old_offset][2][wall_array[old_wall_index].start[1]] = 0;
                world[wall_array[old_wall_index].start[0]+old_offset][3][wall_array[old_wall_index].start[1]] = 0;
                world[wall_array[old_wall_index].start[0]+old_offset][4][wall_array[old_wall_index].start[1]] = 0;
                break;
            case 1:
                world[wall_array[old_wall_index].start[0]-old_offset][1][wall_array[old_wall_index].start[1]] = 0;
                world[wall_array[old_wall_index].start[0]-old_offset][2][wall_array[old_wall_index].start[1]] = 0;
                world[wall_array[old_wall_index].start[0]-old_offset][3][wall_array[old_wall_index].start[1]] = 0;
                world[wall_array[old_wall_index].start[0]-old_offset][4][wall_array[old_wall_index].start[1]] = 0;
                break;
            case 2:
                world[wall_array[old_wall_index].start[0]][1][wall_array[old_wall_index].start[1]+old_offset] = 0;
                world[wall_array[old_wall_index].start[0]][2][wall_array[old_wall_index].start[1]+old_offset] = 0;
                world[wall_array[old_wall_index].start[0]][3][wall_array[old_wall_index].start[1]+old_offset] = 0;
                world[wall_array[old_wall_index].start[0]][4][wall_array[old_wall_index].start[1]+old_offset] = 0;
                break;
            case 3:
                world[wall_array[old_wall_index].start[0]][1][wall_array[old_wall_index].start[1]-old_offset] = 0;
                world[wall_array[old_wall_index].start[0]][2][wall_array[old_wall_index].start[1]-old_offset] = 0;
                world[wall_array[old_wall_index].start[0]][3][wall_array[old_wall_index].start[1]-old_offset] = 0;
                world[wall_array[old_wall_index].start[0]][4][wall_array[old_wall_index].start[1]-old_offset] = 0;
                break;
        }

        switch(new_wall.direction)
        {
          case 0:
              world[new_wall.start[0]+new_offset][1][new_wall.start[1]] = 2;
              world[new_wall.start[0]+new_offset][2][new_wall.start[1]] = 2;
              world[new_wall.start[0]+new_offset][3][new_wall.start[1]] = 2;
              world[new_wall.start[0]+new_offset][4][new_wall.start[1]] = 2;
              break;
          case 1:
              world[new_wall.start[0]-new_offset][1][new_wall.start[1]] = 2;
              world[new_wall.start[0]-new_offset][2][new_wall.start[1]] = 2;
              world[new_wall.start[0]-new_offset][3][new_wall.start[1]] = 2;
              world[new_wall.start[0]-new_offset][4][new_wall.start[1]] = 2;
              break;
          case 2:
              world[new_wall.start[0]][1][new_wall.start[1]+new_offset] = 2;
              world[new_wall.start[0]][2][new_wall.start[1]+new_offset] = 2;
              world[new_wall.start[0]][3][new_wall.start[1]+new_offset] = 2;
              world[new_wall.start[0]][4][new_wall.start[1]+new_offset] = 2;
              break;
          case 3:
              world[new_wall.start[0]][1][new_wall.start[1]-new_offset] = 2;
              world[new_wall.start[0]][2][new_wall.start[1]-new_offset] = 2;
              world[new_wall.start[0]][3][new_wall.start[1]-new_offset] = 2;
              world[new_wall.start[0]][4][new_wall.start[1]-new_offset] = 2;
              break;
        }

        old_offset--;
        new_offset++;
    }

    if(old_offset <= 0)
    {
        wall_array[old_wall_index] = new_wall;
        wall_toggle = 0;
        old_offset = 5;
        new_offset = 1;
    }
}
