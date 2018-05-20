#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Elevator.h"
#include "Passenger.h"
#include <cstdio>
#include "Cout.h"
class World
{
public:
	World(int t) :time(0), man(0)  //��������
	{
		for (int i = 1; i <= Maxfloor; i++)
		{
			for (int j = 1; j <= Maxfloor; j++) a[i][j] = 0;
		}
		for (int i = 1; i <= 3; i++) Ele[i].begin(i);
	}
	std::queue<Passenger> pas; // �ȴ��ĳ˿Ͷ���
	Elevator Ele[4];   // ��̨����
	int N;  //������
	int time;  // ��ǰʱ��
	int clock;  // ������ʱ��
	int man; // ��ǰʱ����������
	int a[Maxfloor + 1][Maxfloor + 1];  // �˿���i¥ȥ��j¥ ������ 
	void scin();  //����
	void dispatch();  //����
	void scout(); //���
};