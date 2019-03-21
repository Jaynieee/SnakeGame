#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")

//贪吃蛇 1界面，2蛇，3食物
//枚举方向
enum Ch
{
	up=72,down=80,left=75,right=77
	//不能随便输，是键盘上上下左右的键值
	//上下左右哦是双码键
};
struct Coor
{
    int x;
	int y;
};


struct Food
{
	Coor fzb;//食物坐标
	bool isEat;//是否吃掉
}food;
//蛇
struct Snake
{
	int n;//蛇的节数
	Ch ch;//方向
	Coor szb[100];//每节的坐标
	
}snake;//snake就是蛇

//初始化蛇
void Snakeinit();
void DrawSnake();
void MoveSnake();
void ChangeCh();
void DrawFood();
void CreateFood();
void EatFood();
void GameOver();