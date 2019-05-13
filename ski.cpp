#include "ski.h"

Jumper::Jumper(std::string na, std::string n, unsigned short a, int dis, int no, float pts, float s)
{
	name = na;
	nationality = n;
	age = a;
	distance = dis;
	notess = no;
	points = pts;
	sum = s;
	std::cout << name << ' ' << nationality << ' ' << age << std::endl;
}

float Jumper::point_counter(Jumper &jump)
{
	points = 150.0;
	if (jump.distance < k_point)
	{
		for (float i = k_point; i > jump.distance; i-- )
		{
			points -= 1.2;
		}
	}
	else if (jump.distance > k_point)
	{
		for (float i = k_point; i < jump.distance; i++ )
		{
			points += 1.2;
		}
	}
	else
	{
		points = 150.0;
	}
	sum = points + notess;
	return sum;
}

int Jumper::jump()
{
	for (int i = 0; i < 4; i++)
	{
		Sleep(1000);
		std::cout << ". ";
	}
	distance = ((std::rand() % 83) + 170);
	std::cout << "\nOdleglosc: "<< distance << " m." << std::endl;
	return distance;
}


int Jumper::notes()
{
	notess = 0;
	int judge[3];
	for (int i = 0; i < 3; i++)
	{
		judge[i] = ((std::rand() % 4) + 16);
		notess += judge[i];
	}
	std::cout << "Noty sedziowskie: " << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << i + 1 << ": "<< judge[i] << std::endl;
		Sleep(1000);
	}
	return notess;
}

std::ostream & operator<<(std::ostream & os, Jumper & obj)
{
	os << obj.name << ' ' << obj.nationality << std::endl;
	return os;
}
