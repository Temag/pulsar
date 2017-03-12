

INCLUDES = -F/System/Library/Frameworks -framework OpenGL -framework GLUT -lm
Executable = a3

a1: a1.c wallfunctions.c enemyfunctions.c Game_Engine/graphics.c Game_Engine/visible.c Game_Engine/graphics.h a1.h
	gcc -w a1.c wallfunctions.c enemyfunctions.c Game_Engine/graphics.c Game_Engine/visible.c -o $(Executable) $(INCLUDES)

clean:
	rm $(Executable)
