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