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
    printf("\n�������Թ�����\n");
    scanf("%d", &maze.col);
    printf("\n\n�밴�������Թ���1��ʾͨ·��0��ʾ�ϰ�:\n\n");
    for(i=0; i<maze.row; i++)
        for(j=0; j<maze.col; j++)
            scanf("%d", &maze.m[i][j]);
    printf("\n������������꣺���� ����(�磺0 2)\n");
    scanf("%d %d", &entry._row, &entry._col);
    printf("\n������������꣺���� ����(�磺5 2)\n");
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
}//��ӡ�Թ�

int CheckAccess(Pos next)
{
	if ((next._col >= 0) && (next._row >= 0)
		&& (next._col < N) && (next._row < N))//�ж��Ƿ�Խ��
	{
		if (maze.m[next._row][next._col] == 1)//��һ���Ƿ���ͨ·
		{
			return 1;//1��ʾ����ͨ��
		}
	}
	return 0;//�޷�ͨ������0
}//�ж���һ���Ƿ��ͨ��

int MazeCheckIsAccess(Pos cur, Pos next)
{
	//�ж�Խ������
	if ((next._col >= 0 && next._row >= 0
		&& next._col < N && next._row<N)
		&& (maze.m[next._row][next._col] == 1
		|| maze.m[next._row][next._col]>maze.m[cur._row][cur._col] + 1))
	{
		return 1;
	}
	//return 0��ʾ������ͨ��
	return 0;
}//Ѱ�����·��̽����һ���Ƿ��ͨ��

int pathsize = 0;

int MazeGetPath()
{
    pathsize = 0;
	Pos cur = entry;//��¼�Թ����
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//���������ѹջ
	maze.m[entry._row][entry._col] = 2;//�߹��ĵط���Ϊ2
	while (StackEmpty(&path))//ջ��Ϊ��ʱ������
	{
		cur = StackTop(&path);
		maze.m[cur._row][cur._col] = 2;//�߹��ĵط���Ϊ2
		if (cur._row==end._row && cur._col == end._col)//�ߵ�����
		{
			if ((pathsize == 0) || StackSize(&path)<pathsize)//�Ѿ��ҵ����ڻ�������������ʱ
			{
				pathsize = StackSize(&path);//·��Ϊ��һ���ߵ�����Ϊ׼
				return 1;
			}
		}
		//��
		Pos next = cur;
		next._row += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._row -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		StackPop(&path);//����
	}
	return 0;
}//��ȡһ���߳��Թ���·��

int MazeGetShortPath()
{
	Pos cur = entry;//��¼�Թ����
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//���������ѹջ
	maze.m[entry._row][entry._col] = 2;//�߹��ĵط���Ϊ2
	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		if (cur._col == 5)
		{
			if ((pathsize == 0) || StackSize(&path) < pathsize)//�Ѿ��ҵ����ڻ�������������ʱ
			{
				pathsize = StackSize(&path);//·��Ϊ��һ���ߵ�����Ϊ׼
			}
		}

		//��
		Pos next = cur;
		next._row -= 1;
		if (MazeCheckIsAccess(cur,next))
		{
			maze.m[next._row][next._col] = maze.m[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//��
		next = cur;
		next._row += 1;
		if (MazeCheckIsAccess(cur,next))
		{
			maze.m[next._row][next._col] = maze.m[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze.m[next._row][next._col] = maze.m[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//��
		next = cur;
		next._col += 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze.m[next._row][next._col] = maze.m[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//����
		StackPop(&path);
	}
	return 0;
}//��Ѱ���·��

void TestMaze()
{
	Pos entry;
	entry._row = 5;
	entry._col = 2;
	/*Pos exit;
	exit._row = 4;
	exit._col = 5;*/
	MazePrint();
	//printf("�Ƿ��г��ڣ�%d\n",MazeGetPath(entry,exit));
	MazeGetShortPath(entry);
	printf("Shortest path%d\n", pathsize);
	MazePrint();
}
