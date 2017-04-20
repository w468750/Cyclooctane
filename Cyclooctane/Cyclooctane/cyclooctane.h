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

struct Vector;
struct Charactor;  // ��ɫ
struct Monster;   //С��
struct Boss;   //boss
struct Prop;   //����
struct Obstacle;  // �ϰ�
struct Room;  // ����
struct Bullet;  // �ӵ�
struct Square;

void gotoxy(int x,int y);
void hidden();  //���ع��

struct Vector
{
	double x,y;
public:
	Vector(double x1, double y1);
	Vector(const Vector& a);
	Vector() ;

	Vector operator = (Vector a);
	Vector operator - (Vector a);

	Vector vertical() ; //����������䴹ֱ����
	double get_lenth();
	Vector new_normalize();
	double dotmulti(Vector a);
};

struct Bullet
{
	double pos_x,pos_y;
	double xita;
	bool exist;
	int life;
	double speed;
	struct Bullet *nex;
public:
	static int num_time_count;
	Bullet(double x,double y,double xi);
	void print_bul_new(double pos_x, double pos_y);
	void print_bul_old(double pos_x, double pos_y);
};


struct Charactor //��ɫ
{
	string name;
	double pos_x,pos_y;
	bool judge_round;   // �ж��ܷ���ת��ͼ  
	Bullet *head,*last;
	int num_bul;
	double speed;
	POINT print_chara[12];
public:
	Charactor();
	~Charactor();
	void print_cha_new(double x,double y,POINT print_chara[]);
	void print_cha_old(double x,double y,POINT print_chara[]);
	void new_point(double x,double y, POINT print_chara[]);
	void print_round_new(double x,double y,POINT print_chara[]);
	void print_part_cha_new(double x,double y, POINT print_chara[]);
	void judge_input();
};

struct Monster //С��
{
protected:
	string name;
	double pos_x,pos_y;
	double speed;
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
	double pos_x,pos_y;
	bool eat;
	bool exist;
public:
	void print_now();
};

struct Obstacle // �ϰ�
{
	double pos_x,pos_y;
	double speed;
	bool judge_show;
public:
	void print_now();
};

struct Room  // ����
{
public:
	//Room();
	//~Room();
	virtual void new_room_point (double pos_x, double pos_y, double angle , POINT pos[])=0;
	virtual void paint_room_new(double pos_x, double pos_y, POINT pos[], double angle)=0;
	virtual void paint_room_old(double pos_x, double pos_y, POINT pos[],double angle)=0;
};

struct Level   // ��
{
	static int num_level;
public:
	Room *room;
	Level();
	~Level();
};

struct Square
{
public:
	double pos_x,pos_y;
	double angle,init;
	int num_com,num_go; //door
	Obstacle *obstacle;
	POINT pos[10];
	POINT edge1[5],edge2[5],edge3[5],edge4[5];
	Square();
	~Square();
	virtual void new_room_point (double squ_x, double squ_y, double angle , POINT pos[]);
	virtual void paint_room_new(double pos_x, double pos_y, POINT pos[], double angle);
	virtual void paint_room_old(double pos_x, double pos_y, POINT pos[],double angle);
	virtual void judge_input(double speed,bool judge_round);
};

struct Game
{
	Charactor ben;
	Level *level;
	Prop *prop;
//	Room *room;
	Square square;
public:
	void startup();
	void updateWithInput();
	void updateWithoutInput();
	void show();
	void judge_bullet(int start, int end, POINT pos[], double &x, double &y, double &xita);
	void update_bullet();
	bool judge_coll_single(POINT first[], int num_first, POINT second[], int num_second, Vector &shadow, double& num_move);  // ��̬ǽ�����˵���ײ���
	bool judge_coll();
	void print_new();
};