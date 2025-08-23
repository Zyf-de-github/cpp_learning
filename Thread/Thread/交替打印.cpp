#if 0

#include <functional>
#include <mutex>
#include <iostream>
#include <condition_variable>
using namespace std;


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class FooBar {
private:
    int n;
    int state; // 0 ��ʾ foo ��ִ�У�1 ��ʾ bar ��ִ��
    mutex m;
    condition_variable cv;

    void printFoo() { cout << "Foo"; }
    void printBar() { cout << "Bar"; }

public:
    FooBar(int n) {
        this->n = n;
        state = 0;
    }

    // foo ��������
    void foo() {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            // �ȴ� state == 0
            cv.wait(lock, [this]() { return state == 0; });
            printFoo();
            state = 1;          // �л��� bar
            cv.notify_one();    // ���� bar �߳�
        }
    }

    // bar ��������
    void bar() {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            // �ȴ� state == 1
            cv.wait(lock, [this]() { return state == 1; });
            printBar();
            state = 0;          // �л��� foo
            cv.notify_one();    // ���� foo �߳�
        }
    }
};

int main() {
    FooBar fb(5); // ��ӡ 5 �� FooBar

    // ֱ�Ӵ���Ա����ָ��Ͷ�������
    thread t1(&FooBar::foo, &fb);
    thread t2(&FooBar::bar, &fb);

    t1.join();
    t2.join();

    cout << endl;
    return 0;
}




//�������÷�
//class FooBar {
//private:
//    int n;
//    int state = 0; // 0 ��ʾ foo ��ִ�У�1 ��ʾ bar ��ִ��
//    mutex m;
//    condition_variable cv;
//    void printBar()
//    {
//        std::cout << "bar";
//    }
//    void printFoo()
//    {
//        std::cout << "Foo";
//    }
//public:
//    FooBar(int n) {
//        this->n = n;
//    }
//    void foo(function<void()> printFoo) //std::function �� C++11 ����� ͨ�ÿɵ��ö����װ����
//    {
//        for (int i = 0; i < n; i++) 
//        {
//            unique_lock<mutex> lock(m);//�Զ���������
//            cv.wait(lock, [this]() { return state == 0; }); //��ν�ʵĵȴ�����������������������������ȴ�
//            this->printFoo();
//            state = 1;           // �л��� bar
//            cv.notify_all();     // ֪ͨ bar ����������
//
//            //notify_all�ǻ����������еȴ��̣߳������̻߳����ν�ʾ���ִ��
//            //ν�ʣ�[this]() { return state == 0; }����һ��bool
//        }
//    }
//
//    void bar(function<void()> printBar) 
//    {
//        for (int i = 0; i < n; i++) 
//        {
//            unique_lock<mutex> lock(m);
//            cv.wait(lock, [this]() { return state == 1; }); // �ȴ� bar ���ִ�
//            this->printBar();
//            state = 0;           // �л��� foo
//            cv.notify_all();     // ֪ͨ foo ����������
//        }
//    }
//};
//
//
//int main() 
//{
//    FooBar fb(5); // ��ӡ 5 �� FooBar
//
//    thread t1(&FooBar::foo, &fb, nullptr);
//    thread t2(&FooBar::bar, &fb, nullptr);
//
//    t1.join();
//    t2.join();
//
//    cout << endl;
//    return 0;
//}



#endif