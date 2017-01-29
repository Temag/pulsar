#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "a1.h"

#include "Game_Engine/graphics.h"

int total_walls = 0;

int wall_toggle = 0;

int new_wall_toggle = 0;

int old_wall_index;

int old_offset = 5;

int new_offset = 1;

clock_t before;

wall new_wall;

wall wall_array[30];

void chooseWall()
{
    int r;
    r = rand() % total_walls;
    old_wall_index = r;

    /*
     Two special cases where the walls starting indeces are the outside wall rather than a pillar
     Changes the starting indeces to that of the closest pillar and generates the new wall using those
     parameteres
     */
    if(wall_array[old_wall_index].start[0] == 42)
    {
        new_wall.start[0] = 36;
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
    else if(wall_array[old_wall_index].start[1] == 42)
    {
        new_wall.start[0] = wall_array[old_wall_index].start[0];
        new_wall.start[1] = 36;
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
         Ignores the direction the old wall was running randomly assigns a direction to the new wall
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


void moveWall()
{
    int i, j, k;
    if(wall_array[old_wall_index].start[0] == 42)
    {
        world[36+old_offset][1][wall_array[old_wall_index].start[1]] = 0;
        world[36+old_offset][2][wall_array[old_wall_index].start[1]] = 0;
        world[36+old_offset][3][wall_array[old_wall_index].start[1]] = 0;
        world[36+old_offset][4][wall_array[old_wall_index].start[1]] = 0;
        if(new_wall_toggle == 0)
        {
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
        }
        old_offset--;
        new_offset++;
    }
    else if(wall_array[old_wall_index].start[1] == 42)
    {
        world[wall_array[old_wall_index].start[0]][1][36+old_offset] = 0;
        world[wall_array[old_wall_index].start[0]][2][36+old_offset] = 0;
        world[wall_array[old_wall_index].start[0]][3][36+old_offset] = 0;
        world[wall_array[old_wall_index].start[0]][4][36+old_offset] = 0;
        if(new_wall_toggle == 0)
        {
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
        if(new_wall_toggle == 0)
        {
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
