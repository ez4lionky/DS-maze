#include "maze.h"
void press_key(){
    //system("pause");
    //system("cls");
    printf("Press any key to continue\n") ;
    getchar();
    getchar();
    system("cls");
}

int main()
{
    int i, cycle=0;
    while(cycle!=-1){
        printf("**************************************\n");
        printf("                  欢迎进入迷宫求解系统\n");
        printf("**************************************\n");
        printf("                  手动生成迷宫 请按：1\n");
        printf("                  自动生成迷宫 请按：2\n");
        printf("                  退出         请按：3\n\n");
        printf("**************************************\n\n");
        printf("请选择你的操作:\n");
        scanf("%d", &i);
        switch(i){
            case 1:
                input();
                MazePrint();
                if(MazeGetPath()==0)
                    printf("该迷宫无解。\n");
                else{
                    MazeGetPath();
                    MazePrint();
                }
                press_key();
                break;
            case 2:
                TestMaze();
                press_key();
                break;
            case 3:
                cycle=-1;
                break;
        }
    }
	system("pause");
	return 0;
}
