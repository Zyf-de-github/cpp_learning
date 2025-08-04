//#include <iostream>
//using namespace std;
//using namespace spacefirst;
//using namespace spacesecond;
//using namespace spacethird;
//
//namespace spacefirst
//{
//	int add(int a,int b)
//	{
//		return a + b;
//	}
//}
//
//
//namespace spacesecond
//{
//	int add(int a, int b, int c, int d)
//	{
//		return a + b + c + d;
//	}
//}
//
//namespace spacethird
//{
//	int add(int a, int b)
//	{
//		return a + b;
//	}
//}

//int main()
//{
//	//int a = 1, b = 4, c = 2, d = 3;
//	//cout << "spacefirst" << spacefirst::add(a, b) << endl;
//	//cout << "spacesecond" << spacesecond::add(a, b,c,d) << endl;
//	//add(a, b);
//	//add(a, b, c, d);
//	cerr << "Variable x = " << 1 << endl;
//	return 0;
//}

//#define CONCAT( x, y )  x ## y
//
//
//
//int main()
//{
//    //cout << "Value of __LINE__ : " << __LINE__ << endl;
//    //cout << "Value of __FILE__ : " << __FILE__ << endl;
//    //cout << "Value of __DATE__ : " << __DATE__ << endl;
//    //cout << "Value of __TIME__ : " << __TIME__ << endl;
//    int CONCAT(cat, 1) = CONCAT(2, 3);
//    cout << cat1;
//
//    return 0;
//}



//
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   线程示例
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <queue>
//#include <string>
//
//// 共享数据队列
//std::queue<std::string> dataQueue;
//// 确认标志（消费者处理完成后回传）
//bool ack = false;
//// 互斥锁（保护共享数据）
//std::mutex mtx;
//// 条件变量（线程间通信）
//std::condition_variable cv_producer, cv_consumer;
//
//// 生产者线程：从终端读取数据并发送
//void producer()
//{
//    while (true)
//    {
//        std::string data;
//
//        // 等待用户输入
//        std::cout << "Producer: Enter data (or 'exit' to quit): ";
//        std::getline(std::cin, data);
//
//        // 如果用户输入 "exit"，则退出
//        if (data == "exit")
//        {
//            std::lock_guard<std::mutex> lock(mtx);
//            dataQueue.push("exit");  // 发送退出信号
//            cv_consumer.notify_one();  // 唤醒消费者
//            break;
//        }
//
//        // 加锁并存入队列
//        {
//            std::lock_guard<std::mutex> lock(mtx);
//            dataQueue.push(data);
//            ack = false;  // 重置确认标志
//            std::cout << "Producer sent: " << data << std::endl;
//        }
//
//        // 通知消费者有新数据
//        cv_consumer.notify_one();
//
//        // 等待消费者处理完成（ack = true）
//        {
//            std::unique_lock<std::mutex> lock(mtx);
//            cv_producer.wait(lock, [] { return ack; });
//            std::cout << "Producer received ack." << std::endl;
//        }
//    }
//}
//
//// 消费者线程：从队列读取数据并显示
//void consumer()
//{
//    while (true)
//    {
//        std::unique_lock<std::mutex> lock(mtx);
//
//        // 等待队列不为空
//        cv_consumer.wait(lock, [] { return !dataQueue.empty(); });
//
//        // 取出数据
//        std::string data = dataQueue.front();
//        dataQueue.pop();
//
//        lock.unlock();  // 提前释放锁
//
//        // 如果收到退出信号，则结束线程
//        if (data == "exit")
//        {
//            std::cout << "Consumer exiting..." << std::endl;
//            break;
//        }
//
//        // 模拟数据处理
//        std::cout << "Consumer received: " << data << std::endl;
//
//        // 发送确认信号（ack = true）
//        {
//            std::lock_guard<std::mutex> lock(mtx);
//            ack = true;
//        }
//        cv_producer.notify_one();  // 唤醒生产者
//    }
//}
//
//int main()
//{
//    // 启动生产者和消费者线程
//    std::thread producerThread(producer);
//    std::thread consumerThread(consumer);
//
//    // 等待线程结束
//    producerThread.join();
//    consumerThread.join();
//
//    std::cout << "All threads finished." << std::endl;
//    return 0;
//}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>

std::mutex mtx;



//void task1(int n)
//{
//	while(true)
//	{
//		mtx.lock();
//		std::cout << " 1111这是第一个线程,传入参数为："<<n << std::endl;
//		mtx.unlock();
//		Sleep(1000);
//	}
//}
//
//void task2(int n)
//{
//	while(true)
//	{
//		mtx.lock();
//		std::cout << " 2222这是第二个线程,传入参数为："<<n << std::endl;
//		mtx.unlock();
//		Sleep(800);
//	}
//}

//#include <queue>
//#include <string>
//std::queue<std::string> q;
//
//void task1(int &n)
//{
//	n = 3;
//}
//
//int main()
//{
//	int a = 2;
//	std::thread t1(task1,std::ref(a));//线程传递引用变量加std::ref声明
//	//std::thread t2(task2,4);
//	t1.join();
//	//t2.join();
//	std::cout << "n= " << a << std::endl;
//
//	std::cout << "退出" << std::endl;
//
//	return 0;
//}



int counter = 0;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        counter++;  // 多线程同时修改，导致数据竞争
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << counter;  // 结果可能小于 200000
}