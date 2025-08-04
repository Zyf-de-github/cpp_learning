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
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   �߳�ʾ��
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <queue>
//#include <string>
//
//// �������ݶ���
//std::queue<std::string> dataQueue;
//// ȷ�ϱ�־�������ߴ�����ɺ�ش���
//bool ack = false;
//// �������������������ݣ�
//std::mutex mtx;
//// �����������̼߳�ͨ�ţ�
//std::condition_variable cv_producer, cv_consumer;
//
//// �������̣߳����ն˶�ȡ���ݲ�����
//void producer()
//{
//    while (true)
//    {
//        std::string data;
//
//        // �ȴ��û�����
//        std::cout << "Producer: Enter data (or 'exit' to quit): ";
//        std::getline(std::cin, data);
//
//        // ����û����� "exit"�����˳�
//        if (data == "exit")
//        {
//            std::lock_guard<std::mutex> lock(mtx);
//            dataQueue.push("exit");  // �����˳��ź�
//            cv_consumer.notify_one();  // ����������
//            break;
//        }
//
//        // �������������
//        {
//            std::lock_guard<std::mutex> lock(mtx);
//            dataQueue.push(data);
//            ack = false;  // ����ȷ�ϱ�־
//            std::cout << "Producer sent: " << data << std::endl;
//        }
//
//        // ֪ͨ��������������
//        cv_consumer.notify_one();
//
//        // �ȴ������ߴ�����ɣ�ack = true��
//        {
//            std::unique_lock<std::mutex> lock(mtx);
//            cv_producer.wait(lock, [] { return ack; });
//            std::cout << "Producer received ack." << std::endl;
//        }
//    }
//}
//
//// �������̣߳��Ӷ��ж�ȡ���ݲ���ʾ
//void consumer()
//{
//    while (true)
//    {
//        std::unique_lock<std::mutex> lock(mtx);
//
//        // �ȴ����в�Ϊ��
//        cv_consumer.wait(lock, [] { return !dataQueue.empty(); });
//
//        // ȡ������
//        std::string data = dataQueue.front();
//        dataQueue.pop();
//
//        lock.unlock();  // ��ǰ�ͷ���
//
//        // ����յ��˳��źţ�������߳�
//        if (data == "exit")
//        {
//            std::cout << "Consumer exiting..." << std::endl;
//            break;
//        }
//
//        // ģ�����ݴ���
//        std::cout << "Consumer received: " << data << std::endl;
//
//        // ����ȷ���źţ�ack = true��
//        {
//            std::lock_guard<std::mutex> lock(mtx);
//            ack = true;
//        }
//        cv_producer.notify_one();  // ����������
//    }
//}
//
//int main()
//{
//    // ���������ߺ��������߳�
//    std::thread producerThread(producer);
//    std::thread consumerThread(consumer);
//
//    // �ȴ��߳̽���
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
//		std::cout << " 1111���ǵ�һ���߳�,�������Ϊ��"<<n << std::endl;
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
//		std::cout << " 2222���ǵڶ����߳�,�������Ϊ��"<<n << std::endl;
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
//	std::thread t1(task1,std::ref(a));//�̴߳������ñ�����std::ref����
//	//std::thread t2(task2,4);
//	t1.join();
//	//t2.join();
//	std::cout << "n= " << a << std::endl;
//
//	std::cout << "�˳�" << std::endl;
//
//	return 0;
//}



int counter = 0;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        counter++;  // ���߳�ͬʱ�޸ģ��������ݾ���
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << counter;  // �������С�� 200000
}