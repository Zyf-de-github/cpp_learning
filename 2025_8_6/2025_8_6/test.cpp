#include "标头.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


//void test()
//{
//	std::vector<char> v1 = { 'a','e','i','o','u' };
//	std::vector<char>::iterator flag;
//	std::string str;
//	for (;;)
//	{
//		bool scan = 0;
//		std::cout << "please enter the words(enter \"exit\" to quit):";
//		std::cin >> str;
//		if (str == "exit")
//		{
//			std::cout << "quiting..."<<std::endl;
//			break;
//		}
//		for(auto temp:str)
//		{
//			flag = std::find(v1.begin(), v1.end(), temp);
//			if (flag != v1.end())
//			{
//				scan = 1;
//				break;
//			}
//		}
//		if (scan)
//		{
//			std::cout << "successful:" << *flag << std::endl;
//		}
//		else
//		{
//			std::cout << "not find" << std::endl;
//		}
//	}
//	std::cout << "quit successful"<<std::endl;
//}





//void test()
//{
//	double a = 0, b = 0, c = 0;
//	for (;;)
//	{
//		cout << "ax^2+bx+c=0" << endl;
//		cout << "a=";
//		cin >> a;
//		cout << "b=";
//		cin >> b;
//		cout << "c=";
//		cin >> c;
//
//		double delta = b * b - 4 * a * c;
//		if (delta > 0)
//		{
//			double x1 = (-b + sqrt(delta)) / (2 * a);
//			cout << "x1=" << x1;
//			double x2 = (-b - sqrt(delta)) / (2 * a);
//			cout << "    x2=" << x2 << endl;
//		}
//		else if (delta == 0)
//		{
//			double x1 = -b  / (2 * a);
//
//			cout << "x1=x2=" << x1 << endl;
//		}
//		else
//		{
//			cout << "x1=" << -b / (2 * a) << "+j" << sqrt(-delta);
//			cout << "    x2=" << -b / (2 * a) << "-j" << sqrt(-delta)<<endl;
//		}
//	}
//}

#include <sstream>

//void test()
//{
//    std::string data = "3397337213@qq.com";
//    std::istringstream iss(data);
//
//    long long num;
//    std::string word;
//
//    if (!(iss >> num)) {
//        std::cout << "提取整数失败！\n";
//        iss.clear(); // 清除错误状态，否则后续操作会直接失败
//    }
//    if (!(iss >> word)) {
//        std::cout << "提取字符串失败！\n";
//    }
//
//    std::cout << num << "\n" 
//        << word << "\n";
//}


#include <iomanip>
//void test()
//{
//	cout << showbase << hex << 42 << endl;
//	cout << setbase(8) << 42 << endl;
//	cout << setbase(2) << 42 << endl;
//}


#include <list>
#include <forward_list>


//void test()
//{
//	list<int> list1 = { 1,2,3,4,5 };
//	for (auto it = list1.begin(); it != list1.end(); it++)
//	{
//		cout << *it;
//	}
//}
//void test()
//{
//	forward_list<int> list1;
//	list1.push_front(1);
//	list1.push_front(2);
//	list1.push_front(3);
//	list1.push_front(4);
//	list1.push_front(5);
//
//	for (auto it = list1.begin(); it != list1.end(); it++)
//	{
//		cout << *it;//5 4 3 2 1
//	}
//}
#include <queue>
//void test()
//{
//	priority_queue<int> pq1;//优先级队列实现最大堆（最小堆）
//	pq1.push(5);
//	pq1.push(3);
//	pq1.push(1);
//	pq1.push(4);
//	pq1.push(2);
//	for (int i = 0; i < 5; i++)
//	{
//		int temp = pq1.top();
//		pq1.pop();
//		cout << temp << ' ';
//	}
//
//}



#include<set>
//void test()
//{
//    std::set<int> mySet;
//
//    // 插入元素
//    mySet.insert(10);
//    mySet.insert(30);
//    mySet.insert(20);
//    mySet.insert(40);
//
//    // 输出 set 中的元素
//    std::cout << "Set contains: ";
//    for (int num : mySet) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    // 查找元素
//    if (mySet.find(20) != mySet.end()) {
//        std::cout << "20 is in the set." << std::endl;
//    }
//    else {
//        std::cout << "20 is not in the set." << std::endl;
//    }
//
//}
 
void test()
{
    std::set<string> mySet;

    // 插入元素
    mySet.insert("aaa");
    mySet.insert("ccc");
    mySet.insert("bbb");
    mySet.insert("ddd");

    // 输出 set 中的元素
    std::cout << "Set contains: ";
    for (string str : mySet) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

}
//void test()
//{
//
//}