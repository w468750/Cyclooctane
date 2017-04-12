#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<string>
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

struct Charactor;  // ��ɫ
struct Monster;   //С��
struct Boss;   //boss
struct Prop;   //����
struct Obstacle;  // �ϰ�
struct Room;  // ����
struct Bullet;  // �ӵ�

void gotoxy(int x,int y);
void hidden();  //���ع��

struct Bullet
{
	int pos_x,pos_y;
	Bullet *next;
public:

};

struct Charactor //��ɫ
{
	string name;
	int pos_x,pos_y;
	bool judge_round;   // �ж��ܷ���ת��ͼ  
	Bullet *bullet;
	int speed;
	POINT print_chara[12];
public:
	Charactor();
	~Charactor();
	void print_cha_new(int x,int y,POINT print_chara[]);
	void print_cha_old(int x,int y,POINT print_chara[]);
	void new_point(int x,int y, POINT print_chara[]);
	void print_round_new(int x,int y,POINT print_chara[]);
	void print_part_cha_new(int x,int y, POINT print_chara[]);
	void judge_input();
};

struct Monster //С��
{
protected:
	string name;
	int pos_x,pos_y;
	int speed;
public:
	void print_now();
};

struct Boss:public Monster // Boss
{
	
public:
	void skill();  //����
	void print_now();
};

struct Prop
{
	string name;
	string describe;
	int pos_x,pos_y;
	bool eat;
	bool exist;
public:
	void print_now();
};

struct Obstacle // �ϰ�
{
	int pos_x,pos_y;
	int speed;
	bool judge_show;
public:
	void print_now();
};

struct Room  // ����
{
	Obstacle *obstacle;
	POINT pos_room[];
public:
	Room();
	~Room();
	void print_now();
	void new_point();
};
struct Level   // ��
{
	static int num_level;
public:
	Room *room;
	Level();
	~Level();
};

struct Game
{
	Charactor ben;
	Level *level;
	Prop *prop;
public:
	void startup();
	void updateWithInput();
	void updateWithoutInput();
	void show();
};