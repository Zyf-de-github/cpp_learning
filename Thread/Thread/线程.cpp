#if 0

#include <thread>
#include <iostream>
#include <Windows.h>

void FirstTask()
{
	while(true)
	{
		std::cout << "task1>>hello world" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
}

void SecondTask()
{
	while (true)
	{
		std::cout << "task2>>hello world" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}
int main()
{
	std::thread thread1(FirstTask);
	std::thread thread2(SecondTask);

	//开发过程严谨判断joinable
	bool IsJoin1 = thread1.joinable();
	bool IsJoin2 = thread2.joinable();
	if (IsJoin1)thread1.join();
	if (IsJoin2)thread2.join();

	return 0;
}
#endif // 
