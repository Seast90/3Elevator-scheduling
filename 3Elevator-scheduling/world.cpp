#include "world.h"

void World::scin()
{
	freopen("input.txt", "r", stdin);
	Passenger p;
	std::cin >> N;
	std::cin >> p;
	pas.push(p);
	clock = p.time;
	for (int i = 2; i <= N; i++)
	{
		std::cin >> p;
		pas.push(p);
		if (p.time == clock)
		{
			p = pas.front();
			a[p.position][p.destination]++;
			a[p.position][0]++;
			pas.pop();
			continue;
		}
		else
		{
			p = pas.front();
			clock = p.time;
			a[p.position][p.destination]++;
			a[p.position][0]++;
			pas.pop();
			dispatch(); //µ÷¶È
		}
	}
	while (!pas.empty())
	{
		p = pas.front();
		a[p.position][p.destination]++;
		a[p.position][0]++;
		pas.pop();
	}
	clock = p.time + 1000;
	dispatch();
	scout();
	fclose(stdin);
}
void World::scout()
{
	Cout q;
	for (int i = 1; i <= 3; i++)
	{
		if (i == 1)freopen("output1.txt", "w", stdout);
		else if (i == 2) freopen("output2.txt", "w", stdout);
		else freopen("output3.txt", "w", stdout);
		while (!Ele[i].scout.empty())
		{
			q = Ele[i].scout.front();
			printf("%d %d\n", q.time, q.position);
			Ele[i].scout.pop();
		}
		fclose(stdout);
	}
}
void World::dispatch()
{
	while (time < clock)
	{
		time++;
		for (int i = 1; i <= 3; i++)
		{
			int pos = Ele[i].position;
			if (Ele[i].desitination[pos]&&(a[pos][0] > 0 || Ele[i].person[pos] > 0)) 
			{
				int flag = 0;
				for (int j = 1; j <= Maxfloor; j++)
					if (Ele[i].desitination[j])
					{
						if (a[pos][j] > 0) flag = 1;
						a[pos][0] -= a[pos][j];
						Ele[i].person[j] += a[pos][j];
						a[pos][j] = 0;
					}
				if ((flag || Ele[i].person[pos] > 0) && Ele[i].action)
				{
					Cout q;
					q.time = time; 
					q.position = pos;
					Ele[i].person[pos] = 0;
					Ele[i].scout.push(q);// { time, Ele[i].postion };
				}
			 }
			else
			{
				int flag = 0;
				if (Ele[i].direction)
				{
					for (int j = pos + 1; j <= Maxfloor; j++)
						if (Ele[i].person[j] > 0 || (Ele[i].desitination[j] &&a[j][0] > 0))
						{
							flag = 1;
							break;
						}
					if (flag)	Ele[i].position++, Ele[i].action = 1;
					else
					{
						for (int j = pos - 1; j >= 1; j--)
							if (Ele[i].person[j] > 0 || (Ele[i].desitination[j] && a[j][0] > 0))
							{
								Ele[i].position--;
								Ele[i].direction = -Ele[i].direction;
								Ele[i].action = 1;
							}
					}
				}
				else
				{
					for (int j = pos - 1; j >= 1; j--)
						if (Ele[i].person[j] > 0 || (Ele[i].desitination[j] && a[j][0] > 0))
						{
							flag = 1;
							break;
						}
					if (flag)	Ele[i].position--, Ele[i].action = 1;
					else
					{
						for (int j = pos + 1; j <= Maxfloor; j++)
							if (Ele[i].person[j] > 0 || (Ele[i].desitination[j] && a[j][0] > 0))
							{
								Ele[i].position++;
								Ele[i].direction = -Ele[i].direction;
								Ele[i].action = 1;
							}
					}
				}
			}
		}
	}
}