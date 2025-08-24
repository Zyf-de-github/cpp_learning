

#if 0
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class FizzBuzz {
private:
    int n;
    int i = 1;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return (i % 3 == 0 && i % 5 != 0) || i > n; });
            if (i > n)return;
            printFizz();
            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return (i % 3 != 0 && i % 5 == 0) || i > n; });
            if (i > n)return;
            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return (i % 3 == 0 && i % 5 == 0) || i > n; });
            if (i > n)return;
            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true)
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return (i % 3 != 0 && i % 5 != 0) || i > n; });
            if (i > n)return;
            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};
#endif



#if 0

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int i = 1;          // ��ǰ����
    int state = 0;      // 0: ��ӡ0, 1: ��ӡ����, 2: ��ӡż��
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) ��� "x"
    void zero(function<void(int)> printNumber) {
        for (int cnt = 0; cnt < n; cnt++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return state == 0; });
            printNumber(0);
            if (i % 2 == 0)
                state = 2; // ��һ��Ӧ�ô�ӡż��
            else
                state = 1; // ��һ��Ӧ�ô�ӡ����
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return state == 2 || i > n; });
            if (i > n) return;   // ��������
            printNumber(i++);
            state = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return state == 1 || i > n; });
            if (i > n) return;   // ��������
            printNumber(i++);
            state = 0;
            cv.notify_all();
        }
    }
};


int main() {
    int n = 10;  // ������޸� n ����
    ZeroEvenOdd zeo(n);

    auto printNumber = [](int x) { cout << x; };

    thread t1(&ZeroEvenOdd::zero, &zeo, printNumber);
    thread t2(&ZeroEvenOdd::even, &zeo, printNumber);
    thread t3(&ZeroEvenOdd::odd, &zeo, printNumber);

    t1.join();
    t2.join();
    t3.join();

    cout << endl;
    return 0;
}

#endif



#if 0

#include <functional>
#include <mutex>
#include <iostream>
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