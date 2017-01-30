
/* Derived from scene.c in the The OpenGL Programming Guide */
/* Keyboard and mouse rotation taken from Swiftless Tutorials #23 Part 2 */
/* http://www.swiftless.com/tutorials/opengl/camera2.html */

/* Frames per second code taken from : */
/* http://www.lighthouse3d.com/opengl/glut/index.php?fps */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "a1.h"

#include "Game_Engine/graphics.h"

	/* mouse function called by GLUT when a button is pressed or released */
void mouse(int, int, int, int);

	/* initialize graphics library */
extern void graphicsInit(int *, char **);

	/* lighting control */
extern void setLightPosition(GLfloat, GLfloat, GLfloat);
extern GLfloat* getLightPosition();

	/* viewpoint control */
extern void setViewPosition(float, float, float);
extern void getViewPosition(float *, float *, float *);
extern void getOldViewPosition(float *, float *, float *);
extern void setViewOrientation(float, float, float);
extern void getViewOrientation(float *, float *, float *);

	/* add cube to display list so it will be drawn */
extern int addDisplayList(int, int, int);

	/* mob controls */
extern void createMob(int, float, float, float, float);
extern void setMobPosition(int, float, float, float, float);
extern void hideMob(int);
extern void showMob(int);

	/* player controls */
extern void createPlayer(int, float, float, float, float);
extern void setPlayerPosition(int, float, float, float, float);
extern void hidePlayer(int);
extern void showPlayer(int);

	/* 2D drawing functions */
extern void  draw2Dline(int, int, int, int, int);
extern void  draw2Dbox(int, int, int, int);
extern void  draw2Dtriangle(int, int, int, int, int, int);
extern void  set2Dcolour(float []);


	/* flag which is set to 1 when flying behaviour is desired */
extern int flycontrol;
	/* flag used to indicate that the test world should be used */
extern int testWorld;
	/* flag to print out frames per second */
extern int fps;
	/* flag to indicate the space bar has been pressed */
extern int space;
	/* flag indicates the program is a client when set = 1 */
extern int netClient;
	/* flag indicates the program is a server when set = 1 */
extern int netServer;
	/* size of the window in pixels */
extern int screenWidth, screenHeight;
	/* flag indicates if map is to be printed */
extern int displayMap;

	/* frustum corner coordinates, used for visibility determination  */
extern float corners[4][3];

	/* determine which cubes are visible e.g. in view frustum */
extern void ExtractFrustum();
extern void tree(float, float, float, float, float, float, int);

extern int total_walls;

extern int wall_toggle;

extern int old_wall_index;

extern int old_offset;

extern int new_offset;

extern clock_t before;

extern wall new_wall;

extern wall wall_array[30];

/********* end of extern variable declarations **************/

	/*** collisionResponse() ***/
	/* -performs collision detection and response */
	/*  sets new xyz  to position of the viewpoint after collision */
	/* -can also be used to implement gravity by updating y position of vp*/
	/* note that the world coordinates returned from getViewPosition()
	   will be the negative value of the array indices */
void collisionResponse() {

	/* your collision code goes here */
	float *x = malloc(sizeof(float)), *y = malloc(sizeof(float)), *z = malloc(sizeof(float));
	int fx, fy, fz, rx, ry, rz;

	getViewPosition(x, y, z);
	fx = (int)(*x * -1);
	fy = (int)(*y * -1);
	fz = (int)(*z * -1);


	/*Collision detection
	Checks if the new position contains a block, if not allows the camera to move
	otherwise returns the camera to the previous position
	*/
	if(world[fx][fy][fz] != 0)
	{
		if(world[fx][fy+1][fz] == 0)
		{
			setViewPosition(*x, *y-1, *z);
		}
		else
		{
			getOldViewPosition(x, y, z);
			setViewPosition(*x, *y, *z);
		}
	}
	/*Gravity
	Reduces camera height on each update until collision detection would take over
	*/
	else if(world[fx][(int)(*y+0.1)*-1][fz] == 0 && flycontrol != 1)
	{
		setViewPosition(*x, *y+0.1, *z);
		getOldViewPosition(x, y, z);
	}

	free(x);
	free(y);
	free(z);
}


	/******* draw2D() *******/
	/* draws 2D shapes on screen */
	/* use the following functions: 			*/
	/*	draw2Dline(int, int, int, int, int);		*/
	/*	draw2Dbox(int, int, int, int);			*/
	/*	draw2Dtriangle(int, int, int, int, int, int);	*/
	/*	set2Dcolour(float []); 				*/
	/* colour must be set before other functions are called	*/
void draw2D() {

   if (testWorld) {
		/* draw some sample 2d shapes */
      GLfloat green[] = {0.0, 0.5, 0.0, 0.5};
      set2Dcolour(green);
      draw2Dline(0, 0, 500, 500, 15);
      draw2Dtriangle(0, 0, 200, 200, 0, 200);

      GLfloat black[] = {0.0, 0.0, 0.0, 0.5};
      set2Dcolour(black);
      draw2Dbox(500, 380, 524, 388);
   } else {

	/* your code goes here */

   }

}


	/*** update() ***/
	/* background process, it is called when there are no other events */
	/* -used to control animations and perform calculations while the  */
	/*  system is running */
	/* -gravity must also implemented here, duplicate collisionResponse */
void update() {
int i, j, k;
float *la;

	/* sample animation for the test world, don't remove this code */
	/* -demo of animating mobs */
   if (testWorld) {

	/* sample of rotation and positioning of mob */
	/* coordinates for mob 0 */
      static float mob0x = 50.0, mob0y = 25.0, mob0z = 52.0;
      static float mob0ry = 0.0;
      static int increasingmob0 = 1;
	/* coordinates for mob 1 */
      static float mob1x = 50.0, mob1y = 25.0, mob1z = 52.0;
      static float mob1ry = 0.0;
      static int increasingmob1 = 1;

	/* move mob 0 and rotate */
	/* set mob 0 position */
      setMobPosition(0, mob0x, mob0y, mob0z, mob0ry);

	/* move mob 0 in the x axis */
      if (increasingmob0 == 1)
         mob0x += 0.2;
      else
         mob0x -= 0.2;
      if (mob0x > 50) increasingmob0 = 0;
      if (mob0x < 30) increasingmob0 = 1;

	/* rotate mob 0 around the y axis */
      mob0ry += 1.0;
      if (mob0ry > 360.0) mob0ry -= 360.0;

	/* move mob 1 and rotate */
      setMobPosition(1, mob1x, mob1y, mob1z, mob1ry);

	/* move mob 1 in the z axis */
	/* when mob is moving away it is visible, when moving back it */
	/* is hidden */
      if (increasingmob1 == 1) {
         mob1z += 0.2;
         showMob(1);
      } else {
         mob1z -= 0.2;
         hideMob(1);
      }
      if (mob1z > 72) increasingmob1 = 0;
      if (mob1z < 52) increasingmob1 = 1;

	/* rotate mob 1 around the y axis */
      mob1ry += 1.0;
      if (mob1ry > 360.0) mob1ry -= 360.0;
    /* end testworld animation */

   } else {

	/* your code goes here */
			/* Move Character*/
       if(wall_toggle == 0)
       {
           wall_toggle = 1;
           chooseWall();
       }

       if(clock() - before > 100000)
       {
           before = clock();
           moveWall();
       }

       collisionResponse();
   }
}

	/* called by GLUT when a mouse button is pressed or released */
	/* -button indicates which button was pressed or released */
	/* -state indicates a button down or button up event */
	/* -x,y are the screen coordinates when the mouse is pressed or */
	/*  released */
void mouse(int button, int state, int x, int y) {

   if (button == GLUT_LEFT_BUTTON)
      printf("left button - ");
   else if (button == GLUT_MIDDLE_BUTTON)
      printf("middle button - ");
   else
      printf("right button - ");

   if (state == GLUT_UP)
      printf("up - ");
   else
      printf("down - ");

   printf("%d %d\n", x, y);
}



int main(int argc, char** argv)
{
int i, j, k, l=0, r;
	/* initialize the graphics system */
   graphicsInit(&argc, argv);

	/* the first part of this if statement builds a sample */
	/* world which will be used for testing */
	/* DO NOT remove this code. */
	/* Put your code in the else statment below */
	/* The testworld is only guaranteed to work with a world of
		with dimensions of 100,50,100. */
   if (testWorld == 1) {
	/* initialize world to empty */
      for(i=0; i<WORLDX; i++)
         for(j=0; j<WORLDY; j++)
            for(k=0; k<WORLDZ; k++)
               world[i][j][k] = 0;

	/* some sample objects */
	/* build a red platform */
      for(i=0; i<WORLDX; i++) {
         for(j=0; j<WORLDZ; j++) {
            world[i][24][j] = 3;
         }
      }
	/* create some green and blue cubes */
      world[50][25][50] = 1;
      world[49][25][50] = 1;
      world[49][26][50] = 1;
      world[52][25][52] = 2;
      world[52][26][52] = 2;

	/* blue box shows xy bounds of the world */
      for(i=0; i<WORLDX-1; i++) {
         world[i][25][0] = 2;
         world[i][25][WORLDZ-1] = 2;
      }
      for(i=0; i<WORLDZ-1; i++) {
         world[0][25][i] = 2;
         world[WORLDX-1][25][i] = 2;
      }

	/* create two sample mobs */
	/* these are animated in the update() function */
      createMob(0, 50.0, 25.0, 52.0, 0.0);
      createMob(1, 50.0, 25.0, 52.0, 0.0);

	/* create sample player */
      createPlayer(0, 52.0, 27.0, 52.0, 0.0);

   } else {

	/* your code to build the world goes here */
	/* initialize world to empty */
       srand(time(NULL));
       before = clock();
      for(i=0; i<WORLDX; i++)
         for(j=0; j<WORLDY; j++)
            for(k=0; k<WORLDZ; k++)
               world[i][j][k] = 0;

			for(i=0; i<43; i++)
			{
				for(j=0; j<43; j++)
				{
						world[i][0][j] = 1;
				}
			}
			for(i=0; i<43; i++)
			{
				for(k=0; k<5; k++)
				{
					world[i][0+k][0] = 2;
					world[i][0+k][42] = 2;
				}
			}

			for(i=0; i<43; i++)
			{
				for(k=0; k<5; k++)
				{
					world[0][0+k][i] = 2;
					world[42][0+k][i] = 2;
				}
			}

			/*createPlayer(0, 52.0, 27.0, 52.0, 0.0);
			setPlayerPosition(0, 1.0, 1, 4.0, 0.0);*/
			setViewPosition(-1.0, -1.0, -1.0);
			setViewOrientation(0.0, 180.0, .0);
			world[3][1][3] = 1;

			/*
			Generate pillars every 6 spaces
			*/
			for(i=6; i<42; i+=6)
			{
				for(j=6; j<42; j+=6)
				{
					/*pillar_array[l].x = i;
					pillar_array[l].y = j;*/
					for(k=1; k<5; k++)
					{
						world[j][k][i] = 2;
					}
					//l++;
				}
			}
       for(i=6; i<48; i+=6)
       {
           for(j=6; j<42; j+=6)
           {
               /*
                Generates walls running in the Z direction (parallel with starting orientation)
                */
               r = rand() % 3;
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
               r = rand() % 3;
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
   }

    /*chooseWall();
    printf("index: %d, direction: %d, NW Direciton: %d\n", old_wall_index, wall_array[old_wall_index].direction, new_wall.direction);*/
	/* starts the graphics processing loop */
	/* code after this will not run until the program exits */
   glutMainLoop();
   return 0;
}
