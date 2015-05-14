#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define maxcmd 200
#define up 72
#define down 80

typedef struct{
	int floor_Number;
	int up_Down;
}CommandList;

void go_To_Sleep();
void signal_Light(int, int);
int  get_Command();



void go_To_Sleep()
{
	Sleep(5000);
}

void signal_Light(int call, int goal)
{



}
int  get_Command()
{
	int flag,i;
	CommandList allCmd[maxcmd] = { 0 };
	while (1)
	{
		allCmd[i].floor_Number = (_getch()-'0');
		flag = _getch();
		if (flag == -32)
		{
			flag = _getch();
			if (flag == up)
				allCmd[i].up_Down = up;
			else if (flag == down)
				allCmd[i].up_Down = down;
			else

		}

	}
}

main()
{
	int maxfloor = 9,go,current=1,goal;
	

}
