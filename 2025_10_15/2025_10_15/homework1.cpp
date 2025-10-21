#if 0
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
using namespace std;

class CVehicle
{
protected:
	int max_speed;
	int speed;
	int weight;
	CVehicle(int max_speed, int speed, int weight) :
		max_speed(max_speed),
		speed(speed),
		weight(weight) {};
public:
	void display()
	{
		cout << "Vechicle:" << endl;
		cout << "max_speed:" << max_speed << endl;
		cout << "speed:" << speed << endl;
		cout << "weight:" << weight << endl;
		cout << endl;
	}
};

class CBicycle :public CVehicle
{
protected:
	int max_speed;
	int speed;
	int weight;
	int height;
	CBicycle(int max_speed, int speed, int weight, int height) :
		CVehicle(max_speed, speed, weight),
		height(height),
		max_speed(max_speed),
		speed(speed),
		weight(weight) {};
public:
	void display()
	{
		cout << "Bicycle:" << endl;
		cout << "max_speed:" << max_speed << endl;
		cout << "speed:" << speed << endl;
		cout << "weight:" << weight << endl;
		cout << "height:" << height << endl;
		cout << endl;
	}
};

class CMotocar :public CVehicle 
{
protected:
	int max_speed;
	int speed;
	int weight;
	int seat_num;
	CMotocar(int max_speed, int speed, int weight, int seat_num) :
		CVehicle(max_speed, speed, weight),
		seat_num(seat_num),
		max_speed(max_speed),
		speed(speed),
		weight(weight) {};
public:
	void display()
	{
		cout << "CMotocar:" << endl;
		cout << "max_speed:" << max_speed << endl;
		cout << "speed:" << speed << endl;
		cout << "weight:" << weight << endl;
		cout << "seat_num:" << seat_num << endl;
		cout << endl;
	}
};

class CMotorcycle :public CBicycle, public CMotocar
{
private:
	int max_speed;
	int speed;
	int weight;
	int height;
	int seat_num;
public:
	CMotorcycle(int max_speed, int speed, int weight, int height, int seat_num) :
		CBicycle(max_speed, speed, weight, height),
		CMotocar(max_speed, speed, weight, seat_num),
		max_speed(max_speed),
		speed(speed),
		weight(weight) ,
		height(height), 
		seat_num(seat_num){};
	void display()
	{
		cout << "CMotorcycle:" << endl;
		cout << "max_speed:" << max_speed << endl;
		cout << "speed:" << speed << endl;
		cout << "weight:" << weight << endl;
		cout << "height:" << height << endl;
		cout << "seat_num:" << seat_num << endl;
		cout << endl;
	}
};
int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	CMotorcycle s(a, b, c, d, e);
	s.CVehicle::display();
	s.CBicycle::display();
	s.CMotocar::display();
	s.CMotorcycle::display();
	return 0;
}

#endif