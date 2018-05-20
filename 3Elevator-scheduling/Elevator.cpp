#include "Elevator.h"

void Elevator::begin(int t) //电梯可达楼层初始化
{
	desitination[1] = 1;
	for (int i = 2; i <= maxfloor; i++)
	{
		if (t == 2) desitination[i] = 1;
		else
		{
			if (i % 2 == 1) 	desitination[i] = 1;
			else desitination[i] = 0;
			if (t == 3) desitination[i] = 1 - desitination[i];
		}
	}
}