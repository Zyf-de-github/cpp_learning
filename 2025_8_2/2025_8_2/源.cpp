#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Books {//c++中拓展了结构体，使其拥有与类相同的功能，包括在内部定义函数，初始化等
	std::string book_name;
	std::string witer;
	std::string subject;
	int  id;

	Books(std::string N, std::string W,std::string S,int a)://冒号初始化序列
		book_name(N),
		witer(W),
		subject(S),
		id(a){}
};


void my_print(Books* book)
{
	std::cout << "name:" << book->book_name << std::endl;
	std::cout << "witer:" << book->witer << std::endl;
	std::cout << "subject:" << book->subject << std::endl;
	std::cout << "id:" << book->id << std::endl;
}

int main()
{
	//Books Book1("C++ 教程", "Runoob", "编程语言", 12345);
	//Books Book2("CSS 教程", "Runoob", "前端技术", 12346);

	//Books* ptrBook1 = &Book1;
	//Books* ptrBook2 = &Book2;

	//my_print(ptrBook1);
	//my_print(ptrBook2);

	std::vector<int> myvector = { 1,5,6,8,4,2,7,3,1,1,6,8 };
	std::sort(myvector.begin(), myvector.end(), [](int a, int b) {
		/*return (a % 2) > (b % 2); */
		return a<b;
		});
	for (auto v : myvector)
	{
		std::cout << v << ' ';
	}
	return 0;
}