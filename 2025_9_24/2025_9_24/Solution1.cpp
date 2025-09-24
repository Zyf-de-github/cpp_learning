#if 0

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Soultion1
{
public:
	vector<int> devided3(long long x)
	{
		int total = 0;
		while (x)
		{
			total += x % 10;
			x /= 10;
		}
		if (total % 3 == 0)return{ total,1 };
		return { total,0 };
	}
};


int main()
{
	Soultion1 x;
	vector<int> v1 = x.devided3(105);
	cout << v1[0] << " " << v1[1] << endl;
	vector<int> v2 = x.devided3(123456789012345678);
	cout << v2[0] << " " << v2[1] << endl;
	vector<int> v3 = x.devided3(10);
	cout << v3[0] << " " << v3[1] << endl;

	return 0;
}

#endif