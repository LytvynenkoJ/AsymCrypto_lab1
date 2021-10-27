#pragma once
#include "mpir.h"
#include "mpirxx.h"
#include <iostream>
#include <fstream>
#include "windows.h"
#include <iomanip>
#include "time.h"
#include <string>
#include "locale.h"
#include <random>
using namespace std;


ofstream out;
const long int length_of_sq = 8000000;
const int n1 = 11;
const int n2 = 9;
const int n3 = 10;
const int n4 = 20;
const int n5 = 89;
const double alph90 = 1.282;
const double alph95 = 1.645;
const double alph99 = 2.326;
int register_L11[n1];
int register_L9[n2];
int register_L10[n3];
int register_L20[n4];
int register_L89[n5];
int sq[length_of_sq];
int help[256][8];
double xi_arr[9];

void obnul()
{
	for (int i = 0; i < length_of_sq; i++)
	{
		sq[i] = 0;
	}
}

void inGen()
{
	mt19937 mersenne{ static_cast<mt19937::result_type>(time(nullptr)) };
	uniform_int_distribution<> rand_val{ 1, 100 };
	for (int i = 0; i < length_of_sq; i++)
	{
		sq[i] = rand_val(mersenne) % 2;
	}
}

void initial_register()
{
	srand(time(0));
	int rand_val = 0;

	POINT p;
	int arr[18];
	for (int i = 0; i < 18; i++)
	{
		GetCursorPos(&p);
		arr[i] = p.x;
		i++;
		arr[i] = p.y;
		Sleep(500);
	}
	
	
	for (int i = 0; i < n1; i++)
	{
		register_L11[i] = arr[0]%2;
		arr[0] = arr[0] / 2;
	}
	rand_val = 1 + rand() % 6;
	for (int i = 0; i < rand_val; i++)
	{
		int temp = 0 + rand() % 10;
		register_L11[temp] = (register_L11[temp]+1) % 2;
	}


	for (int i = 0; i < n2; i++)
	{
		register_L9[i] = arr[1] % 2;
		arr[1] /= 2;
	}
	rand_val = 1 + rand() % 6;
	for (int i = 0; i < rand_val; i++)
	{
		int temp = 0 + rand() % 8;
		register_L9[temp] = (register_L9[temp] + 1) % 2;
	}


	for (int i = 0; i < n3; i++)
	{
		register_L10[i] = arr[2] % 2;
		arr[2] /= 2;
	}
	rand_val = 1 + rand() % 6;
	for (int i = 0; i < rand_val; i++)
	{
		int temp = 0 + rand() % 9;
		register_L10[temp] = (register_L10[temp] + 1) % 2;
	}

	int j = 3;

	for (int i = 0; i < n4; i++)
	{
		register_L20[i] = arr[j] % 2;
		arr[j] /= 2;
		if (arr[j]==0)
		{
			j++;
		}
	}
	rand_val = 1 + rand() % 16;
	for (int i = 0; i < rand_val; i++)
	{
		int temp = 0 + rand() % 19;
		register_L20[temp] = (register_L20[temp] + 1) % 2;
	}


	for (int i = 0; i < 89; i++)
	{
		register_L89[i] = arr[j] % 2;
		arr[j] /= 2;
		if (arr[j] == 0)
		{
			j++;
		}
	}
	rand_val = 10 + rand() % 36;
	for (int i = 0; i < rand_val; i++)
	{
		int temp = 0 + rand() % 88;
		register_L89[temp] = (register_L89[temp] + 1) % 2;
	}
}

int work_of_L11()
{
	int a = 0;
	a = (register_L11[0] + register_L11[2]) % 2;
	int b = register_L11[0];
	for (int i = 0; i < n1 - 1; i++)
	{
		register_L11[i] = register_L11[i + 1];
	}
	register_L11[n1 - 1] = a;
	return b;
}
int work_of_L9()
{
	int a = 0;
	a = (register_L9[0] + register_L9[1] + register_L9[3] + register_L9[4]) % 2;
	int b = register_L9[0];
	for (int i = 0; i < n2 - 1; i++)
	{
		register_L9[i] = register_L9[i + 1];
	}
	register_L9[n2 - 1] = a;
	return b;
}
int work_of_L10()
{
	int a = 0;
	a = (register_L10[0] + register_L10[3]) % 2;
	int b = register_L10[0];
	for (int i = 0; i < n3 - 1; i++)
	{
		register_L10[i] = register_L10[i + 1];
	}
	register_L10[n3 - 1] = a;
	return b;
}
int Geffe()
{
	int z = 0;
	int x = work_of_L11();
	int y = work_of_L9();
	int s = work_of_L10();
	if (s == 0)
		z = y;
	else
		z = x;
	return z;
}

int L20()
{
	int a = 0;
	a = (register_L20[0] + register_L20[11] + register_L20[15] + register_L20[17]) % 2;
	int b = register_L20[0];
	for (int i = 0; i < 19; i++)
	{
		register_L20[i] = register_L20[i + 1];
	}
	register_L20[19] = a;
	return b;
}

int L89()
{
	int a = 0;
	a = (register_L89[0] + register_L89[51]) % 2;
	int b = register_L89[0];
	for (int i = 0; i < 88; i++)
	{
		register_L89[i] = register_L89[i + 1];
	}
	register_L89[88] = a;
	return b;
}

void decToBin()
{
	int p = 0;
	int q = 0;
	for (int i = 1; i < 256; i++)
	{
		p = i;
		for (int j = 0; j < 8; j++)
		{
			q = p % 2;
			help[i][7-j] = q;
			p = p / 2;
			if (p == 0)
				j = 8;
		}
	}
}
int binToDec(int* arr) 
{
	int num = 0;
	for (int i = 0; i < 8; i++)
	{
		num += arr[7 - i] * (1 << i);
	}
	return num;
}

int Biblio()
{
	ifstream in("siempre_estoy_solo.txt");
	if (!in.is_open())
	{
		cout << "Файл не может быть открыт!\n";
		return -1;
	}
	char a;
	for (int i = 0; i < length_of_sq; i++)
	{
		in.get(a);
		for (int j = 0; j < 8; j++)
		{
			int temp = (int)a;
			if (temp < 0)
				temp += 256;
			if (i >= length_of_sq)
			{
				j = 8;
			}
			else
			{
				sq[i] = help[temp][j];
				i++;
			}
		}
	}
}

void Lehmer(int modif)
{
	mt19937 mersenne{ static_cast<mt19937::result_type>(time(nullptr)) };
	uniform_int_distribution<> rand_val{ 11382074, 247483648 };
	unsigned long long int x = rand_val(mersenne);
	unsigned long long int a = (1<<16) + 1;
	unsigned long long int mod = static_cast<unsigned long long int>(1) << 32;

	int i = 0;
	while(i < length_of_sq)
	{
		x = (x * a + 119) % mod;
		int temp = 0;
		if (modif==1)
		{
			temp = x & 255;
		}
		else
		{
			temp = (x >> 24) & 255;
		}
		for (int j = 0; j < 8; j++)
		{
			if (i>=length_of_sq)
			{
				j = 8;
			}
			else
			{
				sq[i] = help[temp][j];
				i++;
			}
		}
	}
}

void Volfram()
{
	int r[32];
	POINT p;
	GetCursorPos(&p);
	for (int i = 0; i < 16; i++)
	{
		r[i] = p.x % 2;
		p.x /= 2;
	}
	for (int i = 16; i < 32; i++)
	{
		r[i] = p.y % 2;
		p.y /= 2;
	}
	Sleep(500);
	int temp = rand() % 10 + 20;
	for (int i = 0; i < temp; i++)
	{
		int j = 0 + rand() % 31;
		r[j] = (r[j] + 1) % 2;
	}

	for (int i = 0; i < length_of_sq; i++)
	{
		sq[i] = r[31];
		int r_right1[32];
		int r_left1[32];
		for (int i = 0; i < 32; i++)
		{
			if (i == 31)
				r_right1[i] = r[0];
			else
				r_right1[i] = r[i + 1];
			if (i == 0)
				r_left1[i] = r[31];
			else
				r_left1[i] = r[i - 1];
		}
		for (int i = 0; i < 32; i++)
		{
			r[i] = r_left1[i] ^ (r_right1[i] | r[i]);
		}
	}
}

string initialString(int size)
{
	srand(time(0));
	int rand_size = 10 + rand() % (size-10);
	string number;
	for (int i = 0; i < rand_size; i++)
	{
		int temp = 0 + rand() % 15;
		if (temp < 10) 
			number += (char)(temp + 48);
		else 
			number += (char)(temp + 55);
	}
	return number;
}

void BM(int modif)
{
	mpz_class p = mpz_class("CEA42B987C44FA642D80AD9F51F10457690DEF10C83D0BC1BCEE12FC3B6093E3", 16);
	mpz_class q = mpz_class("675215CC3E227D3216C056CFA8F8822BB486F788641E85E0DE77097E1DB049F1", 16);
	mpz_class a = mpz_class("5B88C41246790891C095E2878880342E88C79974303BD0400B090FE38A688356", 16);
	string initial = initialString(60);
	mpz_class T = mpz_class(initial, 16);
	int i = 0;
	while (i<length_of_sq)
	{
		if (modif == 1)
		{
			if (mpz_cmp(T.get_mpz_t(), q.get_mpz_t()) < 0)
			{
				sq[i] = 1;
			}
			else
			{
				sq[i] = 0;
			}
			i++;
		}
		if (modif == 2)
		{
			mpz_class T2 = T;
			T2 = T * 128;
			mpz_class temp;
			temp = T2 % q;
			T2 = T2 / q;
			if (temp == 0)
			{
				T2 = T2 - 1;
			}
			unsigned long long int T3 = T2.get_ui();
			for(int j = 0; j < 8; j++)
			{
				int tmp = 0;
				tmp = T3 % 2;
				sq[i] = tmp;
				T3 = T3 / 2;
				i++;
			}
		}
		mpz_powm(T.get_mpz_t(), T.get_mpz_t(), a.get_mpz_t(), p.get_mpz_t());
	}
}

void BBS(int modif)
{
	mpz_class p = mpz_class("D5BBB96D30086EC484EBA3D7F9CAEB07", 16);
	mpz_class q = mpz_class("425D2B9BFDB25B9CF6C416CC6E37B59C1F", 16);
	mpz_class n;
	n = p * q;
	string initial = initialString(50);
	mpz_class r = mpz_class(initial, 16);
	int i = 0;
	while (i<length_of_sq)
	{
		mpz_class temp;
		if (modif == 1)
		{
			temp = r % 2;
			if (temp == 0)
				sq[i] = 0;
			else
				sq[i] = 1;
			i++;
		}
		if (modif == 2)
		{
			mpz_class r2;
			r2 = r;
			for (int j = 0; j < 8; j++)
			{
				temp = r2 % 2;
				r2 = r2 / 2;
				if (temp == 0)
					sq[i] = 0;
				else
					sq[i] = 1;
				i++;
			}
		}
		temp = 2;
		mpz_powm(r.get_mpz_t(), r.get_mpz_t(), temp.get_mpz_t(), n.get_mpz_t());
	}
}

void probabTest()
{
	int* arr = new int[8];
	int count[256];
	for (int i = 0; i < 256; i++)
	{
		count[i] = 0;
	}
	int i = 0;
	while (i<length_of_sq)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[j] = sq[i];
			i++;
		}
		int temp = binToDec(arr);
		count[temp]++;
	}
	int n = length_of_sq / 8;
	n = n / 256;
	double xi = 0;
	for (int j = 0; j < 256; j++)
	{
		xi = xi + (count[j] - n) * (count[j] - n) / n;
	}
	
	cout << "probability test xi^2:  " << xi << endl << "Tests for alpha = 0.9, 0.95, 0.99:   ";
	out.open("results.csv", ios::app);
	for (int i = 0; i < 3; i++)
	{
		if (xi <= xi_arr[i])
		{
			out << xi << " (+);";
			cout << i+1 << " - true       ";
		}
		else
		{
			out << xi << " (-);";
			cout << i+1 << " - false       ";
		}
	}
	cout << endl;
	out.close();
	
}

void indepTest()
{
	int* arr = new int[8];
	int count[257][257];
	for (int i = 0; i < 257; i++)
	{
		for (int j = 0; j < 257; j++)
		{
			count[i][j] = 0;
		}
	}
	int i = 0;
	while (i < length_of_sq)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[j] = sq[i];
			i++;
		}
		int temp1 = binToDec(arr);
		for (int j = 0; j < 8; j++)
		{
			arr[j] = sq[i];
			i++;
		}
		int temp2 = binToDec(arr);
		count[temp1][temp2]++;
	}
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			count[i][256] += count[i][j];
		}
	}
	for (int j = 0; j < 256; j++)
	{
		for (int i = 0; i < 256; i++)
		{
			count[256][j] += count[i][j];
		}
	}
	double xi = 0;
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			if (count[256][j] != 0 && count[i][256] != 0)
			{
				xi = xi + pow(count[i][j], 2) / (count[256][j] * count[i][256]);
			}
		}
	}
	xi = xi - 1;
	xi = xi * length_of_sq / 16;
	cout << "independency test xi^2:  " << xi << endl << "Tests for alpha = 0.9, 0.95, 0.99:   ";
	out.open("results.csv", ios::app);
	for (int i = 3; i < 6; i++)
	{
		if (xi <= xi_arr[i])
		{
			out << xi << " (+);";
			cout << i - 2 << " - true       ";
		}	
		else
		{
			out << xi << " (-);";
			cout << i - 2 << " - false       ";
		}
	}
	cout << endl;
	out.close();
}

void uniformTest()
{
	int* arr = new int[8];
	int count[256][17];
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			count[i][j] = 0;
		}
	}
	int m = length_of_sq / 128;
	int j = 0;
	int co = 0;
	while(co < length_of_sq)
	{
		for (int i = 0; i < m; i++)
		{
			for (int k = 0; k < 8; k++)
			{
				arr[k] = sq[co];
				co++;
			}
			int temp = binToDec(arr);
			count[temp][j]++;
		}
		j++;

	}
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			count[i][16] += count[i][j];
		}
	}
	double xi = 0;
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (count[i][16] != 0)
			{
				xi = xi + pow(count[i][j], 2) / (count[i][16] * m);
			}
		}
	}
	xi = xi - 1;
	xi = xi * length_of_sq / 8;
	cout << "uniformity test xi^2:  " << xi << endl << "Tests for alpha = 0.9, 0.95, 0.99:   ";
	out.open("results.csv", ios::app);
	for (int i = 6; i < 9; i++)
	{
		if (xi <= xi_arr[i])
		{
			out << xi << " (+);";
			cout << i - 5 << " - true       ";
		}
		else
		{
			out << xi << " (-);";
			cout << i - 5 << " - false       ";
		}
	}
	out << "\n";
	cout << endl;
	out.close();
}
