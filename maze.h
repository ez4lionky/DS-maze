#ifndef Maze
	#define Maze
#include "stack.h"

void MazePrint();
int MazeGetPath();
int MazeCheckIsAccess(Pos cur, Pos next);
int MazeGetShortPath();
int CheckAccess(Pos next);
void TestMaze();

#endif
