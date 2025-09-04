#if 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <new>
using namespace std;



class Solution1 {
private:
    vector<vector<char>> x;
    int n;
    int m;
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int num = 0;
        x = grid;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (x[i][j] == '0' || x[i][j] == '2')continue;
                else
                {
                    num++;
                    finding(i, j);
                }
            }
        }
        return num;
    }
    void finding(int i, int j)
    {
        if (x[i][j] == '1')
        {
            x[i][j] = '2';
            if (i + 1 < m) finding(i + 1, j);
            if (j + 1 < n) finding(i, j + 1);
            if (i - 1 >= 0) finding(i - 1, j);
            if (j - 1 >= 0) finding(i, j - 1);
        }
        return;
    }
};
class Solution2 {
private:
    int m, n;
    vector<vector<int>> grid;
public:
    int orangesRotting(vector<vector<int>>& x) {
        grid = x;
        m = grid.size();
        n = grid[0].size();

        int total = 0;

        while (true) {
            bool change = false; // 本轮是否有变化
            bool hasFresh = false; // 是否还有新鲜橘子

            // 本轮传染
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) {
                        infect(i, j, change);
                    }
                    if (grid[i][j] == 1) {
                        hasFresh = true;
                    }
                }
            }

            if (!change) {            // 没有变化
                if (hasFresh) return -1; // 还有新鲜橘子 -> 不可能腐烂完
                else return total;       // 没有新鲜橘子 -> 全部腐烂，返回结果
            }

            // 把本轮新烂的橘子（3）转成正式的烂橘子（2）
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 3) grid[i][j] = 2;
                }
            }

            total++; // 每轮结束，时间+1
        }
    }
    void infect(int i, int j, bool& change) {
        if (i + 1 < m && grid[i + 1][j] == 1) { grid[i + 1][j] = 3; change = true; }
        if (i - 1 >= 0 && grid[i - 1][j] == 1) { grid[i - 1][j] = 3; change = true; }
        if (j + 1 < n && grid[i][j + 1] == 1) { grid[i][j + 1] = 3; change = true; }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) { grid[i][j - 1] = 3; change = true; }
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = nums.size();
        for (int i = 1; i < x; i++)
        {
            if (nums[i] == nums[i - 1])return nums[i];
        }
        return 0;
    }
};

class MyCircularQueue2 {
private:
    int ptr_f = 0;
    int ptr_l = 0;
    int max = 0;
    vector<int> fifo;
public:
    MyCircularQueue2(int k) {
        fifo.assign(k, -1);
        ptr_f = 0;
        ptr_l = 0;
        max = k;
    }

    bool enQueue(int value) {
        if (ptr_l - ptr_f >= max)return false;
        fifo[ptr_l % max] = value;
        ptr_l++;
        return true;
    }

    bool deQueue() {
        if (ptr_f == ptr_l)return false;
        ptr_f++;
        return true;
    }

    int Front() {
        if (ptr_f == ptr_l)return -1;
        int temp = ptr_f;
        ptr_f++;
        return fifo[temp - 1 % max];
    }

    int Rear() {
        if (ptr_f == ptr_l)return -1;
        int temp = ptr_l;
        ptr_l--;
        return fifo[temp - 1 % max];
    }

    bool isEmpty() {
        if (ptr_f == ptr_l)return true;
        return false;
    }

    bool isFull() {
        if (ptr_f - ptr_l + 1 == max)return true;
        return false;
    }
};
class MyCircularQueue1 {
private:
    int ptr_f = 0;
    int ptr_l = 0;
    int max = 0;
    vector<int> fifo;
public:
    MyCircularQueue1(int k) {
        fifo.assign(k, -1);
        max = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        fifo[ptr_l % max] = value;
        ptr_l++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        ptr_f++;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return fifo[ptr_f % max];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return fifo[(ptr_l - 1 + max) % max];
    }

    bool isEmpty() {
        return ptr_f == ptr_l;
    }

    bool isFull() {
        return (ptr_l - ptr_f) == max;
    }
};


int main()
{
    MyCircularQueue1* circularQueue = new MyCircularQueue1(3); // 设置长度为 3
    circularQueue->enQueue(1);  // 返回 true
    circularQueue->enQueue(2);  // 返回 true
    circularQueue->enQueue(3);  // 返回 true
    circularQueue->enQueue(4);  // 返回 false，队列已满
    circularQueue->Rear();  // 返回 3
    circularQueue->isFull();  // 返回 true
    circularQueue->deQueue();  // 返回 true
    circularQueue->enQueue(4);  // 返回 true
    circularQueue->Rear();  // 返回 4

    return 0;
}

#endif