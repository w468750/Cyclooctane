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
	Game cycloocatane;
	cycloocatane.startup();    // ���ݳ�ʼ��
	while(1)  //  ��Ϸѭ��ִ��
	{
		cycloocatane.show();   // ��ʾ����
		cycloocatane.updateWithoutInput();  // �������޹صĸ���
		cycloocatane.updateWithInput();    // �������йصĸ���
		cycloocatane.show();
		Sleep(50);
	}
	return 0;
}

