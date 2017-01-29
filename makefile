

INCLUDES = -F/System/Library/Frameworks -framework OpenGL -framework GLUT -lm

a1: a1.c wallfunctions.c Game_Engine/graphics.c Game_Engine/visible.c Game_Engine/graphics.h a1.h
	gcc a1.c wallfunctions.c Game_Engine/graphics.c Game_Engine/visible.c -o a1 $(INCLUDES)

