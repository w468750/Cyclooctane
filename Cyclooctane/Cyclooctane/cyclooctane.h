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

void gotoxy(int x,int y);
void startup();  //��ʼ�� ���桢��Ϸ���ݳ�ʼ��
void show();  
void updateWithoutInput();  //�������޹����ݵĸ���
void updateWithInput();  // ������������ݸ���

struct Charactor //��ɫ
{
	string name;
	int pos_x,pos_y;
	int direction;
	bool judge_round;
public:
	void print_now();
};

struct Monster //С��
{
protected:
	string name;
	int pos_x,pos_y;
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

public:
	void print_now();
};

struct Room  // ����
{
	Obstacle *obstacle;

public:
	void print_now();
};