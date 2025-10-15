#if 0

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
using namespace std;

//class test1
//{
//private:
//	double length1, length2;
//	double width1, width2;
//	double height1, height2;
//	double ans1, ans2;
//public:
//	void get_val()
//	{
//		cin >> length1 >> width1 >> height1 >> length2 >> width2 >> height2;
//	}
//	void calculate()
//	{
//		ans1 = length1 * width1 * height1;
//		ans2 = length2 * width2 * height2;
//	}
//	void print()
//	{
//		cout << ans1 << " " << ans2 << endl;
//	}
//};
//int main()
//{
//	test1 t;
//	while (true)
//	{
//		t.get_val();
//		t.calculate();
//		t.print();
//	}
//	return 0;
//}

class my_rank
{
	vector<vector<int>> v;
	vector<vector<int>> mul;
public:
	my_rank()
	{
		v.assign(3, vector<int>(3, 0));
		mul.assign(3, vector<int>(3, 0));
	}
	void get_nums()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> v[i][j];
			}
		}
	}
	void operator+(my_rank other)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				v[i][j]+=other.v[i][j];
			}
		}
	}
	void operator*(my_rank other)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//v[i][j]
				int temp = 0;
				for (int m = 0; m < 3; m++)
				{
					temp = temp + v[i][m] * other.v[m][j];
				}
				mul[i][j] = temp;
			}
		}
	}
	void print()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << v[i][j]<<" ";
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << mul[i][j]<<" ";
			}
		}
	}
};

int main()
{
	my_rank r1,r2;
	r1.get_nums();
	r2.get_nums();
	r1* r2;
	r1 + r2;
	r1.print();
	return 0;
}
//3 4 5 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9



//class Vector {
//	int size;
//	int* buffer;
//public:
//	Vector(int s = 100);
//	Vector(const Vector& v);
//	void display();
//	void set();
//	~Vector();
//};
//Vector::Vector(int s) {
//	buffer = new int[size = s];
//	for (int i = 0; i < size; i++)
//		buffer[i] = i * i;
//}
//Vector::Vector(const Vector& v) {
//	size = v.size;
//	buffer = new int[size];
//	for (int i = 0; i < size; i++)
//		buffer[i] = v.buffer[i];
//}
//void Vector::display() {
//	for (int j = 0; j < size; j++)
//		cout << buffer[j] << " ";
//	cout << endl;
//}
//void Vector::set() {
//	for (int j = 0; j < size; j++)
//		buffer[j] = j + 1;
//}
//Vector::~Vector() { delete[]buffer; }
//
//int main() {
//	int n;
//	cin >> n;
//	Vector a(n);
//	Vector b(a);
//	a.set();
//	b.display();
//}
#endif