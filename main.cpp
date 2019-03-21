#include "main.h"

int main()
{
	initgraph(640,480);
		
	/*
	颜色图形音乐图片像素
	*/
	Snakeinit();
	
	while(1)
	{
		//kbhit()检测按键，有返回1 否则返回0
		while(!kbhit())
		{
			if(food.isEat){ CreateFood();}

		   MoveSnake();
		   DrawSnake();
		   DrawFood();
		   EatFood();
		   GameOver();
		   Sleep(80);
		}
	     ChangeCh();		
	}	
	getchar();
	return 0;
}
//初始化蛇
void Snakeinit()
{

	srand((unsigned int)time(NULL));

	//mciSendString(L"open 甩葱歌.mp3 alias BGM", 0, 0, 0);
	//mciSendString(L"play BGM repeat", 0, 0, 0);

	snake.n = 3;
	snake.ch = up;
	snake.szb[0].x=30;
	snake.szb[0].y=200;
	snake.szb[1].x=20;
	snake.szb[1].y=200;
	snake.szb[2].x=10;
	snake.szb[2].y=200;

	food.isEat = true;
}
//绘制蛇
void DrawSnake()
{
	//system("cls");//清控制台
	cleardevice();//清窗口
	for( int i=0;i < snake.n; i++)
	{
	 rectangle(snake.szb[i].x,snake.szb[i].y,
		snake.szb[i].x+10,snake.szb[i].y+10);
	}
}
//蛇的移动
void MoveSnake()
{
	//节n继承节n-1的坐标
	for(int i=snake.n-1;i>0;i--)
	{
		snake.szb[i].x=snake.szb[i-1].x;
		snake.szb[i].y=snake.szb[i-1].y;
	}


	//三大控制结构 分支 if switch
	//蛇头移动
	switch(snake.ch)
	{
	case up:
		snake.szb[0].y-=10;
		break;
	case down:
		snake.szb[0].y+=10;
		break;
	case left:
		snake.szb[0].x-=10;
		break;
	case right:
		snake.szb[0].x+=10;
		/*for(int i=0;i<snake.n;i++)
		{
		       snake.szb[i].x+=10;
		}*/
		break;	
	}
	
}
//改变方向
void ChangeCh()
{
	int move;
	move = getch();//获取按键
	switch(move)
	{
	case up:
		if(snake.ch != down)
		   snake.ch = up;
		break;
	case down:
		if(snake.ch != up)
		   snake.ch = down;
		break;
	case left:
		if(snake.ch != right)
		   snake.ch = left;
		break;
	case right:
		if(snake.ch != left)
		   snake.ch = right;
		break;
	}
}

void CreateFood()
{
	//蛇的轨道上
	food.fzb.x =rand() % 64*10;
	food.fzb.y =rand() % 48*10;
	//有食物
	food.isEat=false;//没有被吃
}
void DrawFood()
{
	roundrect(food.fzb.x,food.fzb.y,
		food.fzb.x+10,food.fzb.y+10,10,10);
}
void EatFood()
{
	if(snake.szb[0].x == food.fzb.x&&snake.szb[0].y==food.fzb.y)
   {
	   snake.n++;
	   food.isEat =true;
   }
}
void GameOver()
{
	//蛇头跟边界
	if (snake.szb[0].x<0 || snake.szb[0].x>640 ||
		snake.szb[0].y<0 || snake.szb[0].y>480)
	{
		closegraph();
		exit(0);
	}

	//吃到自己  蛇头跟蛇身体
	for (int i = snake.n - 1; i > 0; i--)
	{
		if (snake.szb[0].x == snake.szb[i].x&&snake.szb[0].y == snake.szb[i].y)
		{
			closegraph();
			exit(0);
		}
	}
}