#if 0

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Soultion0
{
public:
	int triangle(int a, int b, int c)
	{
		double p = (a + b + c) / 2.0;
		if (a == max(a, max(b, c)))
		{
			if (a < b + c)return (p * (p - a) * (p - b) * (p - c));
			else return 0;
		}
		else if (b == max(a, max(b, c)))
		{
			if (b < a + c)return (p * (p - a) * (p - b) * (p - c));
			else return 0;
		}
		else if (c == max(a, max(b, c)))
		{
			if (c < a + b)return (p * (p - a) * (p - b) * (p - c));
			else return 0;
		}
	}
};


int main()
{
	Soultion0 x;
	cout << x.triangle(3, 4, 5) << endl;
	cout << x.triangle(5, 5, 7) << endl;
	cout << x.triangle(2, 3, 5) << endl;
	return 0;
}

#endif