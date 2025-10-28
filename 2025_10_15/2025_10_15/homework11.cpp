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
#include <unordered_set>
#include <random>
using namespace std;


class teacher
{
public:
	vector<vector<int>> teacher_points;
	vector<int> teacher_average;
	teacher()
	{
		teacher_points.clear();
		teacher_average.clear();
	}
	void add_average(double x)
	{
		teacher_average.push_back(x);
	}
	void add_point(vector<int> y)
	{
		teacher_points.push_back(y);
	}
	void show()
	{
		int m = teacher_points.size();
		int n = teacher_points[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "Teacher" << i + 1 << "->" << "Student" << j + 1 << ":" << teacher_points[i][j] << endl;
			}
			cout << "The average record(Teacher" << i + 1 << "):" << teacher_average[i] << endl;
		}
	}
};
class student
{
public:
	vector<vector<int>> students_points;
	vector<int> students_average;
	student()
	{
		students_points.clear();
		students_average.clear();
	}
	void add_average(int x)
	{
		students_average.push_back(x);
	}
	void add_point(vector<int> y)
	{
		students_points.push_back(y);
	}
	void show()
	{
		int m = students_points.size();
		int n = students_points[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "Student" << j + 1 << "->" << "Teacher" << i + 1 << ":" << students_points[i][j] << endl;
			}
			cout << "The average grade of Teacher" << i + 1 << ":" << students_average[i] << endl;
		}
	}
};

int main()
{
	teacher T;
	student S;
	int m = 0, n = 0;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		int total = 0;
		vector<int> y;
		for (int j = 0; j < n; j++)
		{
			int x = 0;
			cin >> x;
			total += x;
			y.push_back(x);
		}
		T.add_point(y);
		T.add_average(round(total / n));
	}
	for (int i = 0; i < m; i++)
	{
		int total = 0;
		vector<int> y;
		for (int j = 0; j < n; j++)
		{
			int x = 0;
			cin >> x;
			total += x;
			y.push_back(x);
		}
		S.add_point(y);
		S.add_average(round(total / n));
	}
	T.show();
	S.show();
	return 0;
}

#endif


//1 3
//80 90 100
//4 5 4

//2 3
//80 90 100
//75 85 95
//4 5 4
//4 3 4