#if 1

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


class StackOfPlates {
public:
    vector<stack<int>> v;
    int num = 0;
    int size;

    StackOfPlates(int cap)
    {
        size = cap;
        if (cap > 0) v.push_back(stack<int>());
    }

    void push(int val) {
        if (v.empty()) {
            v.push_back(stack<int>());
            num = 0;
        }

        if (v[num].size() == size) {
            num++;
            v.push_back(stack<int>());
        }
        v[num].push(val);
    }

    int pop() {
        if (v.empty()) return -1;
        while (!v.empty() && v[num].empty()) {
            v.pop_back();
            num--;
        }

        if (v.empty()) return -1;

        int temp = v[num].top();
        v[num].pop();

        if (v[num].empty()) {
            v.pop_back();
            num--;
        }

        return temp;
    }

    int popAt(int index) {
        if (index < 0 || index >= (int)v.size()) return -1;
        if (v[index].empty()) return -1;

        int temp = v[index].top();
        v[index].pop();

        if (v[index].empty()) {
            v.erase(v.begin() + index);
            num = (int)v.size() - 1;
        }

        return temp;
    }
};




#endif