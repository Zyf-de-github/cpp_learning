//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <queue>
//#include <string>
//
//std::queue<std::string> dataQueue;
//std::mutex mtx;
//std::condition_variable cv_consumer, cv_producer;
//bool ack = false;
//
//
//void producer()
//{
//	while (1)
//	{
//		mtx.lock();
//		std::cout << "please enter the data(enter exit to quit): ";
//		std::string a;
//		std::cin >> a;
//		dataQueue.push(a);
//		mtx.unlock();
//
//		if (a == "exit")
//		{
//			cv_consumer.notify_one();
//			mtx.lock();
//			std::cout << "producer exit" << std::endl;
//			mtx.unlock();
//			break;
//		}
//		else
//		{
//			cv_consumer.notify_one();
//		}
//		std::unique_lock<std::mutex> lock(mtx);
//		cv_producer.wait(lock, []() {return ack; });//ack为假则阻塞，为真则运行
//		ack = false;
//		lock.unlock();
//	}
//}
//
//void consumer()
//{
//	while (1)
//	{
//		std::unique_lock<std::mutex> lock(mtx);
//		//wait必须配合unique_lock使用
//		cv_consumer.wait(lock, []() {return !dataQueue.empty(); });
//		std::string data = dataQueue.front();
//		dataQueue.pop();
//		lock.unlock();
//
//		if (data == "exit")
//		{
//			mtx.lock();
//			std::cout << "consumer exit"<< std::endl;
//			mtx.unlock();
//			break;
//		}
//		else
//		{
//			mtx.lock();
//			std::cout << "consumer received: " << data << std::endl;
//			mtx.unlock();
//		}
//
//		mtx.lock();
//		ack = true;
//		cv_producer.notify_one();
//		mtx.unlock();
//	}
//}
//
//int main()
//{
//	std::thread thread_producer(producer);
//	std::thread thread_consumer(consumer);
//	//thread_producer.join();
//	//thread_consumer.join();
//	thread_producer.detach();
//	thread_consumer.detach();
//	while (1)
//	{
//		;
//	}
//	return 0;
//}



#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
//#include <>