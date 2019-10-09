# pulsar
This repository contains a 3D version of the arcade game Pulsar that was created for the Video Game Programming Class at University of Guelph using OpenGL.<br/>
Notable achievements:<br/>
* Pseudo random wall generation
* Pseudo random wall movement
* Player collision
* Enemies
  * Simple artificial intelligence
  * Player detection through line of sight

# Authors
Braydon Johnson

# Building the Project
To build this project simply navigate to the project directory with the makefile using the terminal window and type `make`.<br/>
Note: The makefile for this project was created for use with Unix commands, and also requires OpenGL; the path leading to OpenGL needs to be included in the makefile under the *Includes* variable.<br/>
Run `make clean` to delete the executable.

# Running the Project
To run the project, first build it by running `make`. Then run the following command:<br/>
```
./a4
```
