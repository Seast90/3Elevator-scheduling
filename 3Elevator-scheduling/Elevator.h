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
	int direction; //电梯方向
	int position;// 电梯位置
	int desitination[Maxfloor + 1];
	int person[Maxfloor + 1];// 电梯中去往 i 楼层的人数 person[i];
	std::string s; // 记录电梯运作的字符串0代表停 1代表向下 2 代表向上
	//std::vector <int> person;  	
	//std::vector<Passenger> per;
	bool action;
	std::queue<Cout>scout;
	int time; // 当前时间
	int wait; // 电梯外等待人数
	int n;

	void begin(int t);

	//void search();     // 查找
};
