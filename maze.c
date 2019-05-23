#include "maze.h"
#define N 40

struct Maze_Map{
    int row, col, m[N][N];
}maze;
Pos entry;
Pos end;

void input(){
    int i, j;
    printf("\nPlease enter the row number\n");
    scanf("%d", &maze.row);
    printf("\nPlease enter the column number\n");
    scanf("%d", &maze.col);
    printf("\n\n1 presents pass, 0 presents wall:\n\n");
    for(i=0; i<maze.row; i++)
        for(j=0; j<maze.col; j++)
            scanf("%d", &maze.m[i][j]);
    printf("\nPlease enter row and column number of entry point:\n");
    scanf("%d %d", &entry._row, &entry._col);
    printf("\nPlease enter row and column number of end point:\n");
    scanf("%d %d", &end._row, &end._col);
    /*
    printf("\n请输入迷宫列数\n");
    scanf("%d", &maze.col);
    printf("\n\n请按行输入迷宫，1表示通路，0表示障碍:\n\n");
    for(i=0; i<maze.row; i++)
        for(j=0; j<maze.col; j++)
            scanf("%d", &maze.m[i][j]);
    printf("\n请输入起点坐标：行数 列数(如：0 2)\n");
    scanf("%d %d", &entry._row, &entry._col);
    printf("\n请输入起点坐标：行数 列数(如：5 2)\n");
    scanf("%d %d", &end._row, &end._col);
    */
}

void MazePrint()
{
	int i=0;
	int j=0;
	printf("\nMaze:\n");
	for (i=0; i<maze.row; i++)
	{
		for (j = 0; j< maze.col; j++)
		{
			printf("%d ", maze.m[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}//打印迷宫

int CheckAccess(Pos next)
{
	if ((next._col >= 0) && (next._row >= 0)
		&& (next._col < N) && (next._row < N))//判断是否越界
	{
		if (maze.m[next._row][next._col] == 1)//下一步是否是通路
		{
			return 1;//1表示可以通过
		}
	}
	return 0;//无法通过返回0
}//判断下一步是否可通过

int MazeCheckIsAccess(Pos cur, Pos next)
{
	//判断越界的情况
	if ((next._col >= 0 && next._row >= 0
		&& next._col < N && next._row<N)
		&& (maze.m[next._row][next._col] == 1
		|| maze.m[next._row][next._col]>maze.m[cur._row][cur._col] + 1))
	{
		return 1;
	}
	//return 0表示不可以通过
	return 0;
}//寻找最短路径探测下一步是否可通过

int pathsize = 0;

int MazeGetPath()
{
    pathsize = 0;
	Pos cur = entry;//记录迷宫入口
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//将入口坐标压栈
	maze.m[entry._row][entry._col] = 2;//走过的地方置为2
	while (StackEmpty(&path))//栈不为空时继续走
	{
		cur = StackTop(&path);
		maze.m[cur._row][cur._col] = 2;//走过的地方置为2
		if (cur._row==end._row && cur._col == end._col)//走到出口
		{
			if ((pathsize == 0) || StackSize(&path)<pathsize)//已经找到出口还可以往上下走时
			{
				pathsize = StackSize(&path);//路径为第一次走到出口为准
				return 1;
			}
		}
		//下
		Pos next = cur;
		next._row += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//上
		next = cur;
		next._row -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//右
		next = cur;
		next._col += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		StackPop(&path);//回溯
	}
	return 0;
}//获取一条走出迷宫的路径

int MazeGetShortPath()
{
	Pos cur = entry;//记录迷宫入口
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//将入口坐标压栈
	maze.m[entry._row][entry._col] = 2;//走过的地方置为2
	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		if (cur._col == 5)
		{
			if ((pathsize == 0) || StackSize(&path) < pathsize)//已经找到出口还可以往上下走时
			{
				pathsize = StackSize(&path);//路径为第一次走到出口为准
			}
		}

		//下
		Pos next = cur;
		next._row -= 1;
		if (MazeCheckIsAccess(cur,next))
		{
			maze.m[next._row][next._col] = maze.m[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//上
		next = cur;
		next._row += 1;
		if (MazeCheckIsAccess(cur,next))
		{
			maze.m[next._row][next._col] = maze.m[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze.m[next._row][next._col] = maze.m[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//右
		next = cur;
		next._col += 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze.m[next._row][next._col] = maze.m[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//回溯
		StackPop(&path);
	}
	return 0;
}//找寻最短路径

void TestMaze()
{
	Pos entry;
	entry._row = 5;
	entry._col = 2;
	/*Pos exit;
	exit._row = 4;
	exit._col = 5;*/
	MazePrint();
	//printf("是否有出口？%d\n",MazeGetPath(entry,exit));
	MazeGetShortPath(entry);
	printf("Shortest path%d\n", pathsize);
	MazePrint();
}
