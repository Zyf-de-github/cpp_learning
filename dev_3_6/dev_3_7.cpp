#include <iostream>
#include <string>
#include <map>
#define endl '\n'
using namespace std;

int main()
{
	long long ans=0;
	map<int,int> m1;
	map<int,int> m2;
	map<int,int> m3;
	map<int,int> m4;
	
	for(int i=1;i<=9;i++)
	{
		string temp=to_string(i);
		int sum_num=0;
		for(int j=0;j<temp.size();j++)sum_num+=temp[j]-'0';
		m1[sum_num]++;
	}
	for(int i=1;i<=9;i++)
	{
		string temp=to_string(i);
		int sum_num=0;
		for(int j=0;j<temp.size();j++)sum_num+=temp[j]-'0';
		ans+=m1[sum_num];
	}
	
	for(int i=1;i<=99;i++)
	{
		string temp=to_string(i);
		int sum_num=0;
		for(int j=0;j<temp.size();j++)sum_num+=temp[j]-'0';
		m2[sum_num]++;
	}
	for(int i=10;i<=99;i++)
	{
		string temp=to_string(i);
		int sum_num=0;
		for(int j=0;j<temp.size();j++)sum_num+=temp[j]-'0';
		ans+=m2[sum_num];
	}
	
	for(int i=1;i<=999;i++)
	{
		string temp=to_string(i);
		int sum_num=0;
		for(int j=0;j<temp.size();j++)sum_num+=temp[j]-'0';
		m3[sum_num]++;
	}
	for(int i=100;i<=999;i++)
	{
		string temp=to_string(i);
		int sum_num=0;
		for(int j=0;j<temp.size();j++)sum_num+=temp[j]-'0';
		ans+=m3[sum_num];
	}
	
	for(int i=1;i<=9999;i++)
	{
		string temp=to_string(i);
		int sum_num=0;
		for(int j=0;j<temp.size();j++)sum_num+=temp[j]-'0';
		m4[sum_num]++;
	}
	for(int i=1000;i<=9999;i++)
	{
		string temp=to_string(i);
		int sum_num=0;
		for(int j=0;j<temp.size();j++)sum_num+=temp[j]-'0';
		ans+=m4[sum_num];
	}
	cout<<ans<<endl;
	return 0;
} 
