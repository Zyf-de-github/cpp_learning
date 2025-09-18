#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

void test1()
{
	std::cout << "I am a student" << std::endl;
}

void test2()
{
	std::cout << "   *" << '\n';
	std::cout << "  ***" << '\n';
	std::cout << " *****" << '\n';
	std::cout << "*******" << '\n';
	std::cout << " *****" << '\n';
	std::cout << "  ***" << '\n';
	std::cout << "   *" << '\n';

}
class test3
{
	//test3 x(1);
	//cout << fixed << setprecision(15) << x.result;
private:
	void calculate(double x)//计算级数
	{
		int i = 1;
		while(i<20)
		{
			result += pow(-1, i + 1) * pow(x, i) / mul(i);
			i++;
		}
	}
	int mul(int n)//计算阶乘
	{
		int temp = 1;
		for (int i = 1; i <= n; i++)
		{
			temp *= i;
		}
		return temp;
	}
public:
	long double result = 1.0;
	test3(double x) { calculate(x); };
};

class test4
{
	//test4 x;
	//for (auto it : x.ans)
	//{
	//	cout << it << ' ';
	//}
public:
	vector<int> ans;
	test4()
	{
		finding_ans();
	}
private:
	void finding_ans()
	{
		for (int i = 101; i < 1000; i++)
		{
			if (finding_prime(i))
			{
				if (i / 100 == i % 10)ans.push_back(i);
			}
		}
	}
	bool finding_prime(int i)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)return false;
		}
		return true;
	}
};

void test5()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10-i; j++)
		{
			cout << ' ';
		}
		for (int j = 10 - i; j < 10; j++)
		{
			cout << '#';
		}
		cout << "   ";
		for (int j = 0; j < i; j++)
		{
			cout << '$';
		}
		for (int j = i; j < 10; j++)
		{
			cout << ' ';
		}
		cout << endl;
	}
}

void test6(int n)
{
	//test6(1);
	//test6(4);
	//test6(8);
	//test6(32);
	//test6(35);
	int x = n / 4;
	cout << pow(2, x)<<endl;
}

void test7()
{
	for (int i = 1; i < 7; i++)
	{
		cout << i << ' ';
		for (int j = 0; j <= 6; j++)
		{
			cout << (j + i - 1)%7 << ' ';
		}
		cout << endl;
	}
}
void test8()
{
	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			cout << '(' << i << ',' << j << ')' << ' ';
		}
		cout << endl;
	}
}
class test9
{
	//test9 x;
	//x.encryption("the result of 3 and 2 is not 8");
	//x.decryption("xqk\"zlvyuz\"wm#7)gpl'5$ry\"vvw$A");
private:
	vector<int>v = { 4,9,6,2,8,7,3 };

public:
	void encryption(string s)//加密
	{
		int ptr = 0;
		string ans;
		for (int i = 0; i < s.size(); i++)
		{
			int a = (int)s[i] + v[ptr % 7];
			a = ((a - 32) % 91) + 32;
			ans=ans + (char)a;
			ptr++;
		}
		cout << ans<<endl;
	}
	void decryption(string s)//解谜
	{
		int ptr = 0;
		string ans;
		for (int i = 0; i < s.size(); i++)
		{
			int a = (int)s[i] - v[ptr % 7];
			a = ((a - 32  + 91) % 91) + 32;
			ans = ans + (char)a;
			ptr++;
		}
		cout << ans<<endl;
	}
};

void mySwap(int& a, int& b)
{
	swap(a, b);
}

int main()
{
	int a = 16, b = 32;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	mySwap(a, b);
	cout << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	return 0;
}