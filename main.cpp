#include "main.h"

int main()
{
	initgraph(640,480);
		
	/*
	��ɫͼ������ͼƬ����
	*/
	Snakeinit();
	
	while(1)
	{
		//kbhit()��ⰴ�����з���1 ���򷵻�0
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
//��ʼ����
void Snakeinit()
{

	srand((unsigned int)time(NULL));

	//mciSendString(L"open ˦�и�.mp3 alias BGM", 0, 0, 0);
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
//������
void DrawSnake()
{
	//system("cls");//�����̨
	cleardevice();//�崰��
	for( int i=0;i < snake.n; i++)
	{
	 rectangle(snake.szb[i].x,snake.szb[i].y,
		snake.szb[i].x+10,snake.szb[i].y+10);
	}
}
//�ߵ��ƶ�
void MoveSnake()
{
	//��n�̳н�n-1������
	for(int i=snake.n-1;i>0;i--)
	{
		snake.szb[i].x=snake.szb[i-1].x;
		snake.szb[i].y=snake.szb[i-1].y;
	}


	//������ƽṹ ��֧ if switch
	//��ͷ�ƶ�
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
//�ı䷽��
void ChangeCh()
{
	int move;
	move = getch();//��ȡ����
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
	//�ߵĹ����
	food.fzb.x =rand() % 64*10;
	food.fzb.y =rand() % 48*10;
	//��ʳ��
	food.isEat=false;//û�б���
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
	//��ͷ���߽�
	if (snake.szb[0].x<0 || snake.szb[0].x>640 ||
		snake.szb[0].y<0 || snake.szb[0].y>480)
	{
		closegraph();
		exit(0);
	}

	//�Ե��Լ�  ��ͷ��������
	for (int i = snake.n - 1; i > 0; i--)
	{
		if (snake.szb[0].x == snake.szb[i].x&&snake.szb[0].y == snake.szb[i].y)
		{
			closegraph();
			exit(0);
		}
	}
}