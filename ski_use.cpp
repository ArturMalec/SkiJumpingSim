/*
 * ski_use.cpp
 *
 *  Created on: 22 mar 2019
 *      Author: Malcini
 */
#include "ski.h"
void timetonext();
void objdata(Jumper & x, float y[], int n);
void classification(std::multimap<float, std::string> mm);
void menu1();
void menu2();
void menu3();
float arradd(float array1[], int a1, float array2[], int a2);

const int N = 5;

int main()
{
	srand(time(NULL));
	std::multimap<float, std::string> results;
	std::multimap<float, std::string> final_results;
	unsigned choice1, choice2, choice3;
	float res[N], res2[N], final[N];

	// -------------------------------------------------------
	std::cout << "ZAWODNICY: \n";
	Jumper one("Kamil Stoch", "POL", 31, 0, 0, 0.0, 0.0);
	Jumper two("Stefan Kraft", "AUT", 25, 0, 0, 0.0, 0.0);
	Jumper three("Daiki Ito", "JPN", 33, 0, 0, 0.0, 0.0);
	Jumper four("Richard Freitag", "GER", 26, 0, 0, 0.0, 0.0);
	Jumper five("Domen Prevc", "SLV", 19, 0, 0, 0.0, 0.0);

	// -------------------------------------------------------

	menu1();
	while (std::cin >> choice1)
	{
		if (choice1 < 1 || choice1 > 2)
		{
			std::cerr << "Niepoprawny wybor. Sproboj jeszcze raz.\n";
			std::cout << ">> ";
			continue;
		}
		else
			break;
	}
		switch (choice1)
		{
		case 1:
			objdata(one, res, 0);
			results.insert(std::make_pair(res[0], "Kamil Stoch"));
			timetonext();
			objdata(two, res, 1);
			results.insert(std::make_pair(res[1], "Stefan Kraft"));
			timetonext();
			objdata(three, res, 2);
			results.insert(std::make_pair(res[2], "Daiki Ito"));
			timetonext();
			objdata(four, res, 3);
			results.insert(std::make_pair(res[3], "Richard Freitag"));
			timetonext();
			objdata(five, res, 4);
			results.insert(std::make_pair(res[4], "Domen Prevc"));
			break;
		case 2:
			return 0;
			break;
		}

	menu2();
	do
	{
	while (std::cin >> choice2)
	{
		if (choice2 < 1 || choice2 > 3)
		{
			std::cerr << "Niepoprawny wybor. Sproboj jeszcze raz.\n";
			std::cout << ">> ";
			continue;
		}
		else
			break;
	}
	switch (choice2)
	{
	case 1:
		objdata(one, res2, 0);
		final[0] = arradd(res, 0, res2, 0);
		final_results.insert(std::make_pair(final[0], "Kamil Stoch"));
		timetonext();
		objdata(two, res2, 1);
		final[1] = arradd(res, 1, res2, 1);
		final_results.insert(std::make_pair(final[1], "Stefan Kraft"));
		timetonext();
		objdata(three, res2, 2);
		final[2] = arradd(res, 2, res2, 2);
		final_results.insert(std::make_pair(final[2], "Daiki Ito"));
		timetonext();
		objdata(four, res2, 3);
		final[3] = arradd(res, 3, res2, 3);
		final_results.insert(std::make_pair(final[3], "Richard Freitag"));
		timetonext();
		objdata(five, res2, 4);
		final[4] = arradd(res, 4, res2, 4);
		final_results.insert(std::make_pair(final[4], "Domen Prevc"));
		break;
	case 2:
		classification(results);
		Sleep(4000);
		menu2();
		break;
	case 3:
		return 0;
		break;
	}
	}
	while(choice2 == 2);
	menu3();
	while (std::cin >> choice3)
	{
		if (choice1 < 1 || choice1 > 2)
		{
			std::cerr << "Niepoprawny wybor. Sproboj jeszcze raz.\n";
			std::cout << ">> ";
			continue;
		}
		else
			break;
	}
	switch(choice3)
	{
	case 1:
		classification(final_results);
		break;
	case 2:
		break;
	}


	system("pause");
	return 0;
}

void objdata(Jumper & x, float y[], int n)
{
	system("cls");
	std::cout << x;
	x.jump();
	x.notes();
	y[n] = x.point_counter(x);
	std::cout << "Nota: " << y[n] << std::endl;
	Sleep(5000);
}


void timetonext()
{
	for (int i = 5; i > 0; --i)
	{
		system("cls");
		std::cout << "Kolejny zawodnik za: " << i;
		Sleep(1000);
	}
}

void classification(std::multimap<float, std::string> mm)
{
	system("cls");
	int i = 0;
	for (std::multimap<float, std::string>::reverse_iterator it = mm.rbegin(); it != mm.rend(); it++)
	{
		i++;
		std::cout << i << ". " << it->first << ' ' << it->second << std::endl;
	}
}

void menu1()
{
	std::cout << "1 <- Rozpocznij pierwsza serie\n";
	std::cout << "2 <- Zakoncz\n";
	std::cout << ">> ";
}

void menu2()
{
	system("cls");
	std::cout << "1 <- Rozpocznij druga serie\n";
	std::cout << "2 <- Zobacz klasyfikacje\n";
	std::cout << "3 <- Zakoncz\n";
	std::cout << ">> ";
}

void menu3()
{
	std::cout << "1 <- Zobacz finalowa klasyfikacje\n";
	std::cout << "2 <- Zakoncz\n";
	std::cout << ">> ";
}

float arradd(float array1[], int a1, float array2[], int a2)
{
	float result = 0.0;
	result = array1[a1] + array2[a2];
	return result;
}
