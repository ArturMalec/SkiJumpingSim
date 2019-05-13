/*
 * ski.h
 *
 *  Created on: 22 mar 2019
 *      Author: Malcini
 */

#ifndef SKI_H_
#define SKI_H_
#include <iostream>
#include <map>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>

static const short k_point = 200;

class Jumper
{
public:
	Jumper(std::string na, std::string n, unsigned short a, int dis, int no, float pts, float s);
	float point_counter(Jumper &jump);
	int jump();
	int notes();
	friend std::ostream & operator<<(std::ostream & os, Jumper & obj);
	virtual ~Jumper() {}

private:
	std::string name;
	std::string nationality;
	unsigned short age;
	int distance;
	int notess;
	float points;
	float sum;
};
#endif /* SKI_H_ */
