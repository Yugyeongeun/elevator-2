#include <stdio.h> 
#include <conio.h> 
#include<windows.h>
typedef struct{
	int floor_Number;
	int up_Down;
}CommandList;



#define MAXCMD 200

#define BOOL int
#define FALSE 0
#define TRUE 1
#define MAXFLOOR 9

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#define SPACE 32
#define ESC 27
#define ENTER 10


int  get_Command();
int arrowkey(int);
int innerReq(CommandList *, int goal);
int outerReq(CommandList *allCmd);
int go(int cur, int goal);
main()
{
	get_Command();
	
}
int arrowkey(int key)
{
	if (key == UP)//up
		return UP;
	else if (key == DOWN)//down
		return DOWN;
	else
		return 0;

}

int innerReq(CommandList *allCmd, int goal)
{

	(*allCmd).floor_Number = goal;
	(*allCmd).up_Down = 0;
	return TRUE;

}

int outerReq(CommandList *allCmd)
{
	int key2 = _getch();
	if (!(key2 = arrowkey(key2)))
		return -1;

	if (key2 == UP)
	{
		printf("\nUP-");//显示一下
	}
	else if (key2 == DOWN)
	{
		printf("\nDOWN-");//显示一下
	}
	else
		return -1;
	(*allCmd).up_Down = key2;


	int floor;
	while (!isdigit(floor = _getch()))
		;
	putchar(floor);
	putchar(ENTER);//显示一下
	(*allCmd).floor_Number = floor - '0';

	return TRUE;
}


int go(int cur, int goal)
{
	if (cur == goal)
	{
		printf("当前楼层%d\n", cur);
		return cur;
	}
	else if (goal > cur)
	while (goal >= cur)
	{
		printf("当前楼层%d\n", cur);
		Sleep(100);
		if (goal == cur)
			return cur;
		cur++;
	}
	else
	while (goal <= cur)
	{
		printf("当前楼层%d\n", cur);
		Sleep(100);
		if (goal == cur)
			return cur;

		cur--;
	}
	return cur;
	
}


int  get_Command()
{
	int flag = 0, i = 0;
	int curFloor = 1;
	char key = 0;
	CommandList allCmd[MAXCMD] = { 0 };
	while (1)
	{

		if (_kbhit()){
			key = _getch();

			if (isdigit(key)){
				innerReq(&allCmd[i], key - '0');
			}
			else if (key == -32 || 224)//方向键
			{
				outerReq(&allCmd[i]);
			}

			flag = 0;
			i++;
		}	

		if (allCmd[i-1].floor_Number != 0 && flag == 0)
		{
			flag = 1;
			curFloor = go(curFloor, allCmd[i].floor_Number);
		}

	}

	

}
