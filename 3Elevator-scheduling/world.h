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
	World(int t) :time(0), man(0)  //析构函数
	{
		for (int i = 1; i <= Maxfloor; i++)
		{
			for (int j = 1; j <= Maxfloor; j++) a[i][j] = 0;
		}
		for (int i = 1; i <= 3; i++) Ele[i].begin(i);
	}
	std::queue<Passenger> pas; // 等待的乘客队列
	Elevator Ele[4];   // 三台电梯
	int N;  //总人数
	int time;  // 当前时间
	int clock;  // 接下来时间
	int man; // 当前时间请求人数
	int a[Maxfloor + 1][Maxfloor + 1];  // 乘客在i楼去往j楼 的人数 
	void scin();  //读入
	void dispatch();  //调度
	void scout(); //输出
};