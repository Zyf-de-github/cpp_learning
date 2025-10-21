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

class Teacher
{
private:
	string name;
	string age;
	string sex;
	string addr;
	string tele;

	string title;
public:
	Teacher(string name, string age, string sex, string addr, string tele, string title);
	void disply();
};
Teacher::Teacher(string name, string age, string sex, string addr, string tele, string title) :
	name(name),
	age(age),
	sex(sex),
	addr(addr),
	tele(tele),
	title(title) {};
void Teacher::disply()
{
	cout << "Name:" << name << endl;
	cout << "Age:" << age << endl;
	cout << "Sex:" << sex << endl;
	cout << "Addr:" << addr << endl;
	cout << "Tele:" << tele << endl;
	cout << "Title:" << title << endl;
}



class Cader
{
private:
	string name;
	string age;
	string sex;
	string addr;
	string tele;
public:
	string post;
	Cader(string name, string age, string sex, string addr, string tele, string post);
	void disply();
};
Cader::Cader(string name, string age, string sex, string addr, string tele, string post) :
	name(name),
	age(age),
	sex(sex),
	addr(addr),
	tele(tele),
	post(post) {};
void Cader::disply()
{
	cout << "Name:" << name << endl;
	cout << "Age:" << age << endl;
	cout << "Sex:" << sex << endl;
	cout << "Addr:" << addr << endl;
	cout << "Tele:" << tele << endl;
	cout << "Post:" << post << endl;
}



class Teacher_Cader :public Teacher,public Cader
{
private:
	string wages;
public:
	Teacher_Cader(string name, string age, string sex, string addr, string tele, string title, string post,string wages);
	void show();
};
Teacher_Cader::Teacher_Cader(string name, string age, string sex, string addr, string tele, string title, string post, string wages) :
	Teacher(name, age,  sex,  addr,  tele,  title),
	Cader(name, age, sex, addr, tele, post),
	wages(wages){};
void Teacher_Cader::show()
{
	Teacher::disply();
	cout << "Post:" << Cader::post << endl;
	cout << "Wages:" << wages << endl;
}

int main()
{
	string name, age,sex, addr, tele ,title, post,wages;

	getline(cin, name);
	getline(cin, age);
	getline(cin, sex);
	getline(cin, title);
	getline(cin, post);
	getline(cin, addr);
	getline(cin, tele);
	getline(cin, wages);
	Teacher_Cader t(name, age, sex, addr, tele, title, post, wages);
	t.show();
	return 0;
}
//Zhang san
//50
//Male
//Princpial
//Professor
//135 Beijing Road Shanghai
//(021)61234567
//10000
#endif