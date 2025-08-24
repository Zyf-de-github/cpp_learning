

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
    int i = 1;          // 当前数字
    int state = 0;      // 0: 打印0, 1: 打印奇数, 2: 打印偶数
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) 输出 "x"
    void zero(function<void(int)> printNumber) {
        for (int cnt = 0; cnt < n; cnt++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return state == 0; });
            printNumber(0);
            if (i % 2 == 0)
                state = 2; // 下一次应该打印偶数
            else
                state = 1; // 下一次应该打印奇数
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return state == 2 || i > n; });
            if (i > n) return;   // 避免死锁
            printNumber(i++);
            state = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return state == 1 || i > n; });
            if (i > n) return;   // 避免死锁
            printNumber(i++);
            state = 0;
            cv.notify_all();
        }
    }
};


int main() {
    int n = 10;  // 你可以修改 n 测试
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
    int state; // 0 表示 foo 该执行，1 表示 bar 该执行
    mutex m;
    condition_variable cv;

    void printFoo() { cout << "Foo"; }
    void printBar() { cout << "Bar"; }

public:
    FooBar(int n) {
        this->n = n;
        state = 0;
    }

    // foo 不带参数
    void foo() {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            // 等待 state == 0
            cv.wait(lock, [this]() { return state == 0; });
            printFoo();
            state = 1;          // 切换到 bar
            cv.notify_one();    // 唤醒 bar 线程
        }
    }

    // bar 不带参数
    void bar() {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            // 等待 state == 1
            cv.wait(lock, [this]() { return state == 1; });
            printBar();
            state = 0;          // 切换到 foo
            cv.notify_one();    // 唤醒 foo 线程
        }
    }
};

int main() {
    FooBar fb(5); // 打印 5 组 FooBar

    // 直接传成员函数指针和对象引用
    thread t1(&FooBar::foo, &fb);
    thread t2(&FooBar::bar, &fb);

    t1.join();
    t2.join();

    cout << endl;
    return 0;
}




//新特性用法
//class FooBar {
//private:
//    int n;
//    int state = 0; // 0 表示 foo 该执行，1 表示 bar 该执行
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
//    void foo(function<void()> printFoo) //std::function 是 C++11 引入的 通用可调用对象包装器。
//    {
//        for (int i = 0; i < n; i++) 
//        {
//            unique_lock<mutex> lock(m);//自动管理互斥锁
//            cv.wait(lock, [this]() { return state == 0; }); //带谓词的等待，如果条件满足则继续，不满足则等待
//            this->printFoo();
//            state = 1;           // 切换到 bar
//            cv.notify_all();     // 通知 bar 可以运行了
//
//            //notify_all是唤醒其余所有等待线程，其余线程会根据谓词竞争执行
//            //谓词：[this]() { return state == 0; }返回一个bool
//        }
//    }
//
//    void bar(function<void()> printBar) 
//    {
//        for (int i = 0; i < n; i++) 
//        {
//            unique_lock<mutex> lock(m);
//            cv.wait(lock, [this]() { return state == 1; }); // 等待 bar 的轮次
//            this->printBar();
//            state = 0;           // 切换到 foo
//            cv.notify_all();     // 通知 foo 可以运行了
//        }
//    }
//};
//
//
//int main() 
//{
//    FooBar fb(5); // 打印 5 组 FooBar
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