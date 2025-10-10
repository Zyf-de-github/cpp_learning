#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;


void PRN1()
{
	vector<int> g1(10, 1);
	vector<int> g2(10, 1);
	while (true)
	{
		int g1_tmp = g1[2] ^ g1[9];
		int g1_ans = g1[9];
		for (int i = 9; i >0; i--)
		{
			g1[i] = g1[i - 1];
		}
		g1[0] = g1_tmp;

		int g2_tmp = g2[1] ^ g2[2] ^ g2[5] ^ g2[7] ^ g2[8] ^ g2[9];
		int g2_ans = g1_ans ^ g2[1] ^ g2[5];
		for (int i = 9; i > 0; i--)
		{
			g2[i] = g2[i - 1];
		}
		g2[0] = g2_tmp;
		cout << g2_ans;
		Sleep(100);
	}
}

void PRN2()
{
	vector<int> g1(10, 1);
	vector<int> g2(10, 1);
	while (true)
	{
		int g1_tmp = g1[2] ^ g1[9];
		int g1_ans = g1[9];
		for (int i = 9; i > 0; i--)
		{
			g1[i] = g1[i - 1];
		}
		g1[0] = g1_tmp;

		int g2_tmp = g2[1] ^ g2[2] ^ g2[5] ^ g2[7] ^ g2[8] ^ g2[9];
		int g2_ans = g1_ans ^ g2[2] ^ g2[6];
		for (int i = 9; i > 0; i--)
		{
			g2[i] = g2[i - 1];
		}
		g2[0] = g2_tmp;
		cout << g2_ans;
		Sleep(100);
	}
}

int main()
{
	//PRN1();
	//PRN2();
	return 0;
}