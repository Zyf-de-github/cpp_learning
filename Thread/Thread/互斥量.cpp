#if 0

#include <thread>
#include <iostream>
#include <Windows.h>
#include <mutex>

int i = 0;
std::mutex mutex1;
void FirstTask()
{
	while (true)
	{
        //unique_lock<mutex> lock(mutex1);
		mutex1.lock();//不如使用自动管理的互斥锁  
		i++;
		std::cout << "task1>>" << i << std::endl;
		mutex1.unlock();
		if (i >= 20)break;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void SecondTask()
{
	while (true)
	{
		mutex1.lock();
		i++;
		std::cout << "task2>>" << i << std::endl;
		mutex1.unlock();
		if (i >= 20)break;
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