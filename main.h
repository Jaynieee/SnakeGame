#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")

//̰���� 1���棬2�ߣ�3ʳ��
//ö�ٷ���
enum Ch
{
	up=72,down=80,left=75,right=77
	//��������䣬�Ǽ������������ҵļ�ֵ
	//��������Ŷ��˫���
};
struct Coor
{
    int x;
	int y;
};


struct Food
{
	Coor fzb;//ʳ������
	bool isEat;//�Ƿ�Ե�
}food;
//��
struct Snake
{
	int n;//�ߵĽ���
	Ch ch;//����
	Coor szb[100];//ÿ�ڵ�����
	
}snake;//snake������

//��ʼ����
void Snakeinit();
void DrawSnake();
void MoveSnake();
void ChangeCh();
void DrawFood();
void CreateFood();
void EatFood();
void GameOver();