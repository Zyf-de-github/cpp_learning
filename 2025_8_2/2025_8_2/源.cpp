#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#include <queue>           // queue
#include <deque>           // deque
#include <stack>           // stack
#include <unordered_map>   // unordered_map
#include <map>             // map
#include <set>             // set
#include <vector>          // vector
#include <fstream>
using namespace std;
//template<typename T>

//struct Books {//c++����չ�˽ṹ�壬ʹ��ӵ��������ͬ�Ĺ��ܣ��������ڲ����庯������ʼ����
//	std::string book_name;
//	std::string witer;
//	std::string subject;
//	int  id;
//
//	Books(std::string N, std::string W,std::string S,int a)://ð�ų�ʼ������
//		book_name(N),
//		witer(W),
//		subject(S),
//		id(a){}
//};
//
//
//void my_print(Books* book)
//{
//	std::cout << "name:" << book->book_name << std::endl;
//	std::cout << "witer:" << book->witer << std::endl;
//	std::cout << "subject:" << book->subject << std::endl;
//	std::cout << "id:" << book->id << std::endl;
//}
//
//int main()
//{
//	//Books Book1("C++ �̳�", "Runoob", "�������", 12345);
//	//Books Book2("CSS �̳�", "Runoob", "ǰ�˼���", 12346);
//	//Books* ptrBook1 = &Book1;
//	//Books* ptrBook2 = &Book2;
//	//my_print(ptrBook1);
//	//my_print(ptrBook2);
//
//	//std::vector<int> myvector = { 1,5,6,8,4,2,7,3,1,1,6,8 };
//	//std::sort(myvector.begin(), myvector.end(), [](int a, int b) {
//	//	/*return (a % 2) > (b % 2); */
//	//	return a<b;
//	//	});
//	//for (auto v : myvector)
//	//{
//	//	std::cout << v << ' ';
//	//}
//
//
//	//std::vector<int> v = { 10, 20, 30 };
//	//// ʹ�õ�������������
//	//for (auto it = v.begin(); it != v.end(); ++it) {
//	//	std::cout << *it << " ";
//	//}
//
//
//	//struct Node {
//	//	int data;
//	//	Node* next;
//	//};//����
//	//queue<int> q;//����
//	//deque<int> dq;//˫�˶���
//	//stack<int> s;///ջ
//	//unordered_map<string, int> hashTable;//��ϣ��
//	//map<string, int> myMap;//�����
//	//set<int> s;//����
//	//vector<int> v;//��̬����
//
//	return 0;
//}





//class Animal {
//public:
//
//	int age;
//	string name;
//
//	Animal(int a,string b):age(a),name(b){}
//
//
//	virtual void sound() {
//		cout << "animal makes a sound" << endl;
//	}
//
//};
//
//class Cat : public Animal {
//public:
//	Cat(int a, string b) :Animal(a,b) {}
//
//	void sound() override{
//		cout << "a cat named " << name << ' ' << age << " years old " << " makes meows" << endl;
//	}
//
//};
//
//
//class Dog : public Animal {
//public:
//	Dog(int a, string b) :Animal(a, b) {}
//
//	void sound() override {
//		cout << "a dog named " << name << ' ' << age << " years old " << " makes meows" << endl;
//	}
//
//};





//class Shape {
//public:
//	T width;
//	T height;
//
//	Shape(T a, T b) : width(a), height(b) {
//		cout << "this is type: " << typeid(T).name() << endl;
//	}
//
//	virtual T area() = 0;
//};
//
//class Recrangle :public Shape<float> {
//public:
//	Recrangle(float a,float b):Shape<float>(a,b){}
//	float area() override {
//		return width * height;
//	}
//};
//
//class Triangle :public Shape<float> {
//public:
//	Triangle(float a, float b) : Shape(a, b) {}
//	float area() override {
//		return width * height/2.0;
//	}
//};
//
//int main() {
//	//Dog dog(3, "wanwan");
//	//Cat cat(2, "miaomiao");
//	//dog.sound();
//	//cat.sound();
//	Recrangle four(3.0, 4.0);
//	Triangle three(2.0, 4.0);
//	cout << "Recrangle area = " << four.area() << '\n';
//	cout << "Triangle area = " << three.area() << '\n';
//	return 0;
//}





//class Shape {
//public:
//	double width;
//	double height;
//
//	// ģ�幹�캯����֧�ָ������Ͳ���
//	template<typename T1, typename T2>
//	Shape(T1 a, T2 b) : width(static_cast<double>(a)), height(static_cast<double>(b)) {}
//
//	virtual double area() = 0;
//};
//
//class Rectangle : public Shape {
//public:
//	template<typename T1, typename T2>
//	Rectangle(T1 a, T2 b) : Shape(a, b) {}
//
//	double area() override {
//		return width * height;
//	}
//};
//
//int main() {
//	Rectangle r1(3, 4);       // int
//	Rectangle r2(3.5f, 4.2f); // float
//	Rectangle r3(5.5, 6.1);   // double
//
//	cout << r1.area() << endl;
//	cout << r2.area() << endl;
//	cout << r3.area() << endl;
//
//	return 0;
//}


//class Cube
//{
//public:
//	
//	Cube(int a, int  b, int c) :length(a), weight(b), high(c) { square = a * b * c; }
//	void Show()
//	{
//		cout << "the square is: " << square << endl;
//	}
//private:
//	int length;
//	int weight;
//	int high;
//	int square;
//};
//
//int main()
//{
//	Cube cube1(10, 10, 10);
//	cube1.Show();
//	return 0;
//}
//






//// �������
//class Command
//{
//public:
//    virtual void execute() = 0;
//    virtual ~Command() {}
//};
//
//// ��������
//class PrintCommand : public Command
//{
//public:
//    void execute() override
//    {
//        cout << "Print command executed." << endl;
//    }
//};
//
//class SaveCommand : public Command
//{
//public:
//    void execute() override
//    {
//        cout << "Save command executed." << endl;
//    }
//};
//
//class ExitCommand : public Command
//{
//public:
//    void execute() override
//    {
//        cout << "Exit command executed." << endl;
//    }
//};
//
//// ģ�⹤���������������ƴ����������
//Command* createCommandFromName(const string& name)
//{
//    if (name == "print")
//    {
//        return new PrintCommand();
//    }
//    else if (name == "save")
//    {
//        return new SaveCommand();
//    }
//    else if (name == "exit")
//    {
//        return new ExitCommand();
//    }
//    return nullptr;
//}
//
//int main()
//{
//    vector<string> commandNames = { "print", "save", "exit" };
//    vector<Command*> commandList;
//
//    // ��̬�����������
//    for (const string& name : commandNames)
//    {
//        Command* cmd = createCommandFromName(name);
//        if (cmd)
//        {
//            commandList.push_back(cmd);
//        }
//    }
//
//    // ʹ�ö�̬ͳһ���ýӿ�
//    for (Command* cmd : commandList)
//    {
//        cmd->execute();
//    }
//
//    // �ͷ��ڴ�
//    for (Command* cmd : commandList)
//    {
//        delete cmd;
//    }
//
//    return 0;
//}
#include <windows.h>
double division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (a / b);
}

int main()
{
	cout << division(2, 5) << endl;
	Sleep(2);
	cout << division(2, 0) << endl;
	//fstream file1("outfile.txt",ios::app);
	//file1 << "open successful" << endl;
	//file1.close();
	return 0;
}