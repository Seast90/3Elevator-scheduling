#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
//#include "world.h"
#define Maxfloor 10
#include "Cout.h"
class Elevator
{
public:
	Elevator() :maxfloor(Maxfloor), position(1), wait(0), time(0),direction(1), action(0)
	{
		for (int i = 1; i <= Maxfloor; i++)  person[i] = 0;
	}
	int maxfloor;
	int direction; //���ݷ���
	int position;// ����λ��
	int desitination[Maxfloor + 1];
	int person[Maxfloor + 1];// ������ȥ�� i ¥������� person[i];
	std::string s; // ��¼�����������ַ���0����ͣ 1�������� 2 ��������
	//std::vector <int> person;  	
	//std::vector<Passenger> per;
	bool action;
	std::queue<Cout>scout;
	int time; // ��ǰʱ��
	int wait; // ������ȴ�����
	int n;

	void begin(int t);

	//void search();     // ����
};
