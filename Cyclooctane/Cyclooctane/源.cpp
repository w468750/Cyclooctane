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
#include "cyclooctane.h"
using namespace std;


int main()
{
	startup();    // ���ݳ�ʼ��
	srand(time(0));
	while(1)  //  ��Ϸѭ��ִ��
	{
		show();   // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();    // ���û������йصĸ���
		Sleep(100);
	}
	return 0;
}